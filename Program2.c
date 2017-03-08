#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
        
        const int root=0;
        double time1,time2,time3;
        int rank,Buffer,i,j;
        int world_size;

        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

      
        MPI_Comm_size(MPI_COMM_WORLD, &world_size);
        if(rank == root) {
           Buffer = 777;
        }

         

for(j=0;j!=100;j++)
{
 if(rank == root)
 {
    
   time1 = MPI_Wtime();
    for (i = 0; i < world_size; i++) {
      if (i != rank) {
        MPI_Send(&Buffer, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
      }
    }
    time2 = MPI_Wtime();
    time3= time3 + (time2-time1);

  } else {    
    MPI_Recv(&Bufferfer, 1, MPI_INT, root, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }

}


       if(rank==root){
                printf("Average Computation time: %f\n",time3/100);
        }
        MPI_Finalize();
        return 0;
}
