/*Interfaces*/
#include "modulo.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <omp.h>

/*Varaible of high value to reserve memory*/
#define DATA_SZ (1024*1024*64*4)

/*Memory space acordin reserve memory value*/
static double MEM_CHUNK[DATA_SZ];


/*  @breif main(): Main function
*/
int main(int argc, char* argv[]){

    double *Ma,*Mb,*Mc;
    //struct arg_struct args;

    if (argc!=3){
        printf("./MMPosix <matrix size> <# of threads>\n");
        return -1;
    }

    /*Init of global variables*/
    int N           = atof(argv[1]);    /* Matrix's size.*/
    int nthreads    = atof(argv[2]);    /* Number of threads.*/
    
    /*It is validated that the number of threads entered is less than or equal to the 
      number of cores detected by the operating system*/
	if(nthreads > omp_get_max_threads()){
		printf("El número de hilos debe ser <= %d \n",omp_get_max_threads());
		return -1;
	}


    /*Memory creation and reserce for each matrix*/
    Ma = MEM_CHUNK;
    Mb = Ma+N*N;
    Mc = Mb+N*N;
    initMatrix(N,Ma, Mb, Mc);

    /*Matrices are printed*/    
    printMatrix(N,Ma);
    printMatrix(N,Mb);
    

    sampleStart();
    MM1fOMP(nthreads,N,Ma,Mb,Mc);
    sampleEnd();
    
    /*Matrices are printed if N is less than 4*/
    printMatrix(N,Mc);
    

    return EXIT_SUCCESS;
}