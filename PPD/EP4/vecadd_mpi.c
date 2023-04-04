#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define TOL 0.0000001

int main(int argc, char *argv[]) {
    if(argc != 2){
        printf("Usage: ./vecadd_mpi N\n");
        printf("N: Size of the vectors\n");
        
        exit(-1);
    }

    float *a, *b, *c, *res; // arrays of numbers
    int array_size = atoi(argv[1]); // total array size
    int size_per_proc; // array size to be calculated by each proc
    int rank, nprocs; // rank number and number of processes
    int err = 0; // error count
    double t2, t1;
    float * ap;
	float * bp;
	float * cp;

    MPI_Init(&argc,&argv);           
    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);     

    size_per_proc = array_size/nprocs;
    //~~~~MASTER PROCESS~~~~
    if (rank == 0){
        a = (float*) malloc(array_size * sizeof(float));
        b = (float*) malloc(array_size * sizeof(float));
        c = (float*) malloc(array_size * sizeof(float));
        res = (float*) malloc(array_size * sizeof(float));
    
        for (int i = 0; i < array_size; i++){
            a[i] = (float) i;
            b[i] = 2.0 * (float) i;
            c[i] = 0.0;
            res[i] = i + 2 * i;
        }
    }
    //~~~SHARED PROCESS~~~
    ap = (float *) malloc(sizeof(float)*size_per_proc);
	bp = (float *) malloc(sizeof(float)*size_per_proc);
	cp = (float *) malloc(sizeof(float)*size_per_proc);
    
    MPI_Scatter(a, size_per_proc, MPI_FLOAT, ap, size_per_proc, MPI_FLOAT, 0, MPI_COMM_WORLD); 
	// scattering array b from MASTER node out to the other node
	MPI_Scatter(b, size_per_proc, MPI_FLOAT, bp, size_per_proc, MPI_FLOAT, 0, MPI_COMM_WORLD); 
    
    t1 = MPI_Wtime();
    for(int i=0;i<size_per_proc;i++){
		cp[i] = ap[i]+bp[i];
    }
    
    MPI_Gather(cp, size_per_proc, MPI_FLOAT, c, size_per_proc, MPI_FLOAT, 0, MPI_COMM_WORLD);
    
    // test results
    if (rank == 0){
        for (int i = 0; i < array_size; i++){
            float val = c[i] - res[i];
            val = val * val;

            if(val > TOL)
                err++;
        }
        t2 = MPI_Wtime();
        printf("Soma completa com %d erros em %f segundos usando %d processo(s)\n\n", err,t2-t1, nprocs);
        free(a);
        free(b);
        free(c);
        free(ap);
        free(bp);
        free(cp);
    }
    MPI_Finalize();
    return 0;
}