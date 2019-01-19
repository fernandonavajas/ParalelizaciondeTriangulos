#include "mpi.h"
#include <stdio.h>
 
 using namespace std;
 
int main(int argc, char *argv[])
{
    int rank, size, i;
    int matriz[10];
    MPI_Status status;
 
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);// cantidad de procesadores
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);// numero de cada procesador, ordenados por su nivel de ocupación
    if (rank == 0)// cuando sea el primer porcesador
    {
        for (i=0; i<10; i++)
            matriz[i] = i;
        MPI_Send(matriz, 10, MPI_INT, 1, 123, MPI_COMM_WORLD);// enviar la matriz, con 10 datos, de tipo entero, al procesador 1, 
    }
    if (rank == 1)// segundo procesador
    {
        MPI_Recv(matriz, 10, MPI_INT, 0, 123, MPI_COMM_WORLD, &status);// recibe la matriz, con 10 datos, de tipo entero, desde el procesador 0
        for (i=0; i<10; i++)
        {
            if (matriz[i] == i)//si matriz[1]==1.....
				cout<<"esta bien"<<endl;
        }
    }
    MPI_Finalize();
    return 0;
}
