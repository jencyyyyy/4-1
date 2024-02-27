#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int K, M, N, P;
    scanf("%d %d %d %d", &K, &M, &N, &P);

    int A[K][M][N];
    int B[K][N][P];
    int C[K][M][P];

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

    multiply_matrices(K, M, N, P, A, B, C);

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

    return 0;
}