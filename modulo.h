#ifndef MODULO_C_H_INCLUDE
#define MODULO_C_H_INCLUDE

struct arg_struct { 
     int n;
     int NThreads;
     double **Ma;
     double **Mb;
     double **Mc;
     int iDThread;
    };

void sampleStart();
void sampleEnd();
double randNumber();
void initMatrix(int SZ, double *Ma, double *Mb, double *Mc);
void printMatrix(int SZ, double *M);
void MM1c(int size, double *Ma, double *Mb, double *Mc);
void MM1cOMP(int hilos,int size, double *Ma, double *Mb, double *Mc);
void MM1f(int size, double *Ma, double *Mb, double *Mc);
void MM1fOMP(int hilos,int size, double *Ma, double *Mb, double *Mc);
double ** memReserve(int size);
void initMatrix_DoublePointers(double **MA, double **MB, double **MC, int size);
void printMatrix_DoublePointers(double **M, int size);
void *multMM(void *arg);
#endif
