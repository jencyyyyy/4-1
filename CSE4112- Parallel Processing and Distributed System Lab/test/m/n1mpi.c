#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MAX_K 1000
#define MAX_M 1000
#define MAX_N 1000
#define MAX_P 1000

// Function to multiply two matrices
void multiply_matrices(int K, int M, int N, int P, int A[K][M][N], int B[K][N][P], int C[K][M][P]) {
    // Iterate over each matrix
    for (int k = 0; k < K; k++) {
        // Iterate over each row of the resulting matrix
        for (int i = 0; i < M; i++) {
            // Iterate over each column of the resulting matrix
            for (int j = 0; j < P; j++) {
                // Initialize the element of the resulting matrix to 0
                C[k][i][j] = 0;

                // Multiply the corresponding elements of the input matrices
                for (int l = 0; l < N; l++) {
                    C[k][i][j] += A[k][i][l] * B[k][l][j];
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    // Initialize MPI environment
    MPI_Init(&argc, &argv);

    // Get the rank and size of the current process
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Get the input parameters
    int K, M, N, P;
    if (rank == 0) {
        printf("Enter the values of K, M, N, and P: ");
        scanf("%d %d %d %d", &K, &M, &N, &P);
    }

    // Broadcast the input parameters to all processes
    MPI_Bcast(&K, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&P, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Allocate memory for the matrices
    int A[K][M][N];
    int B[K][N][P];
    int C[K][M][P];

    // Initialize the matrices with random values
    if (rank == 0) {
        for (int k = 0; k < K; k++) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    A[k][i][j] = rand() % 10;
                }
            }
        }

        for (int k = 0; k < K; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < P; j++) {
                    B[k][i][j] = rand() % 10;
                }
            }
        }
    }

    // Scatter the matrices to all processes
    MPI_Scatter(A, K * M * N, MPI_INT, A, K * M * N, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(B, K * N * P, MPI_INT, B, K * N * P, MPI_INT, 0, MPI_COMM_WORLD);

    // Start the timer
    double start_time = MPI_Wtime();

    // Multiply the matrices
    multiply_matrices(K, M, N, P, A, B, C);

    // Stop the timer
    double end_time = MPI_Wtime();

    // Gather the resulting matrix to process 0
    MPI_Gather(C, K * M * P, MPI_INT, C, K * M * P, MPI_INT, 0, MPI_COMM_WORLD);

    // Print the resulting matrix
    if (rank == 0) {
        printf("The resulting matrix C is:\n");
        for (int k = 0; k < K; k++) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < P; j++) {
                    printf("%d ", C[k][i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }

        // Print the time taken for multiplication
        printf("Time taken for multiplication: %f seconds\n", end_time - start_time);
    }

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;
}