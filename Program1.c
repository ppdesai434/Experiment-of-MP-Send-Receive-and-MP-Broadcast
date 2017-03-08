#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
        int R;
        int Buffer;
        int i;
        const int root=0;
        double time1,time2,time3;

        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &R);
        

         if(R == root) {
           Buffer = 777;
        }

        for(i=0;i!=100;++i){
       if(R == root) {
           time1 = MPI_Wtime();
           MPI_Bcast(&Buffer, 1, MPI_INT, root, MPI_COMM_WORLD);
           time2 = MPI_Wtime();
           printf( "Time Taken is %f\n .", t2 - t1 );
           time3 += (time2-time1);
         }else{

        MPI_Bcast(&Buffer, 1, MPI_INT, root, MPI_COMM_WORLD);

        }

    }
        if(R==root){
                printf("Average Computation time: %f\n",time3/100);
        }
        MPI_Finalize();
        return 0;
}
