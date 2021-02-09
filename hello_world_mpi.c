#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv)
{
  int my_rank, nproc;
  
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &nproc);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  
  printf("Hello World from process %d of %d\n", my_rank, nproc);
  
  MPI_Finalize();
  return 0;
}
