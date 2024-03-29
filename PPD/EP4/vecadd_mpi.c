#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#include <sys/time.h>
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
    float * ap;
	float * bp;
	float * cp;
    struct timeval time_start;
    struct timeval time_end;

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
    
    // get the start time
    gettimeofday(&time_start, NULL);
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
        // get the end time
            
        gettimeofday(&time_end, NULL);
        double exec_time = (double) (time_end.tv_sec - time_start.tv_sec) +
                       (double) (time_end.tv_usec - time_start.tv_usec) / 1000000.0;
        printf("Soma completa com %d erros em %f segundos usando %d processo(s)\n\n", err,exec_time, nprocs);
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