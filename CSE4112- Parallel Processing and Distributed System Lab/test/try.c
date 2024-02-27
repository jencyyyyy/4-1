#include <stdio.h>
#include <mpi.h>

#define ARRAY_SIZE 10

int main(int argc, char** argv) {
    int my_rank, num_procs;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    // Initialize the array of integers
    int a[ARRAY_SIZE] = {1, 2, 3, 1, 2, 4, 5, 6, 1, 2};

    // Initialize the array of counts
    int c[ARRAY_SIZE] = {0};

    // Each process counts the frequency of integers in the array a
    for (int i = my_rank; i < ARRAY_SIZE; i += num_procs) {
        c[a[i]]++;
    }

    // Reduce the counts from all processes to process 0
    MPI_Reduce(c, c, ARRAY_SIZE, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Process 0 prints the frequency of integers
    if (my_rank == 0) {
        printf("Frequency of integers:\n");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("Integer %d: %d\n", i, c[i]);
        }
    }

    MPI_Finalize();
    return 0;
}
