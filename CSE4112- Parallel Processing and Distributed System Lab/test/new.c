#include<stdio.h>
#include <mpi.h>
#include<string.h>
int  main (int argc, char **argv)
{
    int num_procs; 
    int rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("%d: hello (p=%d)\n", rank, num_procs);
    /* Do many things, all at once */
    MPI_Finalize();
    return 0;
}