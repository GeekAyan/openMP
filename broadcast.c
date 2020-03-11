#include <stdio.h>
#include<math.h>
#include <mpi.h>
int main( int argc, char *argv[] )
{
 int rank, size,n;
 MPI_Init( &argc, &argv );
 MPI_Comm_size(MPI_COMM_WORLD, &size);
 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 for(int i=0;i<(int)sqrt(size)+1;i++){
 	int p=pow(2,i);
	for(int j=0;j<p;j++){
		if(p+j<size){
		if (rank == j) {
 		n = -1;
 		MPI_Send(&n, 1, MPI_INT, p+j, 0, MPI_COMM_WORLD);
 		} 
		else if (rank == p+j) {
 		MPI_Recv(&n, 1, MPI_INT, j, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
 		printf("Process %d received message from process %d\n",p+j,j);
		}
	}
	}
}
 

 
 MPI_Finalize();
 return 0;
} 
