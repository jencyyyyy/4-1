#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int K=1, M, N, P;

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

    int *A = (int *)malloc(K * M * N * sizeof(int));
    int *B = (int *)malloc(K * N * P * sizeof(int));
    int *C = (int *)malloc(K * M * P * sizeof(int));

    if (rank == 0) {
        for (int i = 0; i < K * M * N; i++) {
            A[i] = rand() % 10;
        }

        for (int i = 0; i < K * N * P; i++) {
            B[i] = rand() % 10;
        }
    }

    MPI_Scatter(A, M * N, MPI_INT, A, M * N, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(B, N * P, MPI_INT, B, N * P, MPI_INT, 0, MPI_COMM_WORLD);

    double start = MPI_Wtime();

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            for (int k = 0; k < N; k++) {
                C[i * P + j] += A[i * N + k] * B[k * P + j];
            }
        }
    }

    double end = MPI_Wtime();

    MPI_Gather(C, M * P, MPI_INT, C, M * P, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("%f\n", end - start);
    }

    free(A);
    free(B);
    free(C);

    MPI_Finalize();

    return 0;
}