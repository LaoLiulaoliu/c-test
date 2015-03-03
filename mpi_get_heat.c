#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>


double rand_number()
{
    int max = 20, min = -80;
    srandom( (unsigned)time(NULL) );
    double i = (float)random() / (RAND_MAX + 1.0) * (max - min) + min;
    return exp(i);
}

int main(int argc, char* argv[])
{
    char hostname[MPI_MAX_PROCESSOR_NAME];
    int task_count;
    int rank;
    int len;
    int ret;

    ret = MPI_Init(&argc, &argv);
    if (MPI_SUCCESS != ret) {
        printf("start mpi fail\n");
        MPI_Abort(MPI_COMM_WORLD, ret);
    }

    MPI_Comm_size(MPI_COMM_WORLD, &task_count);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(hostname, &len);

    while(1)
        printf("task_count = %d, my rank = %d on %s, %f\n", task_count, rank, hostname, rand_number());

    MPI_Finalize();
    return 0;
}
