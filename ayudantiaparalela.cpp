#include <iostream>
#include <mpi.h>
#include <stdio.h>
using namespace std;

void mostrar(int array[]){
	for (int i=0; i<800000; i++){
		cout<<array[i]<<endl;
	}
}
int main(int argc, char *argv[] ){
	
	MPI_Status status;
	int procesador, rank, value=189;
	int array[800000];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	MPI_Comm_size(MPI_COMM_WORLD, &procesador);
	
	if(rank==0){
		for(int i=0;i<800000;i++){
			array[i]=i*2;
		}
		MPI_Send(&value,1,MPI_INT,1,0,MPI_COMM_WORLD );
		cout<<"solo soy el 0"<<endl;
		//mostrar(array);
	}
	
	if (rank==1){
		MPI_Recv(&value,1,MPI_INT,0,0,MPI_COMM_WORLD, &status);
		//mostrar(array);
	}
	cout<<rank<<endl;
	MPI_Finalize();
	
	return 0;
}


// mpicc o mpic++  
// mpirun -np 4(numero de procesadores)

// mpic++ ejemplo.cpp -o nombre 
// mpirun -np 8 nombre
