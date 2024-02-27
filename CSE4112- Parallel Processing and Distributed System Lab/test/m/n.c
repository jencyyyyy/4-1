#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MAX_K 1000
#define MAX_M 1000
#define MAX_N 1000
#define MAX_P 1000

void multiply_matrices(int K, int M, int N, int P, int A[K][M][N], int B[K][N][P], int C[K][M][P]) {
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < P; j++) {
                C[k][i][j] = 0;
                for (int l = 0; l < N; l++) {
                    C[k][i][j] += A[k][i][l] * B[k][l][j];
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int K, M, N, P;

    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        scanf("%d %d %d %d", &K, &M, &N, &P);
    }

    MPI_Bcast(&K, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&P, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int A[K][M][N];
    int B[K][N][P];
    int C[K][M][P];

    if (rank == 0) {
        for (int k = 0; k < K; k++) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    scanf("%d", &A[k][i][j]);
                }
            }
        }

        printf("2nd matrix:");
        for (int k = 0; k < K; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < P; j++) {
                    scanf("%d", &B[k][i][j]);
                }
            }
        }
    }

    MPI_Scatter(A, K * M * N / size, MPI_INT, A[0][0][0], K * M * N / size, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(B, K * N * P / size, MPI_INT, B[0][0][0], K * N * P / size, MPI_INT, 0, MPI_COMM_WORLD);

    double start_time = MPI_Wtime();

    multiply_matrices(K, M, N, P, A, B, C);

    double end_time = MPI_Wtime();

    MPI_Gather(C[0][0][0], K * M * P / size, MPI_INT, C[0][0][0], K * M * P / size, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("result:\n");
        for (int k = 0; k < K; k++) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < P; j++) {
                    printf("%d ", C[k][i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }

        printf("Time taken: %f seconds\n", end_time - start_time);
    }

    MPI_Finalize();

    return 0;
}