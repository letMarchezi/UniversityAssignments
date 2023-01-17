/*
    Student name: Leticia Bossatto Marchezi
    Class: High performance programming
    This program solves Laplace's equation on a regular 2D grid using simple Jacobi iteration.
    The stencil calculation stops when  iter > ITER_MAX
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#define ITER_MAX 3000 // number of maximum iterations
#define CONV_THRESHOLD 1.0e-5f // threshold of convergence

pthread_barrier_t barrier;

// matrix to be solved
double **grid;

// auxiliary matrix
double **new_grid;

// size of each side of the grid
int size;
int num_threads;

void *calculate_grid(void *);


// allocate memory for the grid
void allocate_memory(){
    grid = (double **) malloc(size * sizeof(double *));
    new_grid = (double **) malloc(size * sizeof(double *));

    for(int i = 0; i < size; i++){
        grid[i] = (double *) malloc(size * sizeof(double));
        new_grid[i] = (double *) malloc(size * sizeof(double));
    }
}

// initialize the grid
void initialize_grid(){
    // seed for random generator
    srand(10);

    int linf = size / 2;
    int lsup = linf + size / 10;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            // inicializa região de calor no centro do grid
            if ( i>=linf && i < lsup && j>=linf && j<lsup)
                grid[i][j] = 100;
            else
               grid[i][j] = 0;
            new_grid[i][j] = 0.0;
        }
    }
}

// save the grid in a file
void save_grid(){

    char file_name[30];
    sprintf(file_name, "grid_laplace.txt");

    // save the result
    FILE *file;
    file = fopen(file_name, "w");

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            fprintf(file, "%lf ", grid[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Usage: ./laplace_seq N T\n");
        printf("N: The size of each side of the domain (grid)\n");
        printf("N: The amount of threads used\n");
        exit(-1);
    }
    // variables to measure execution time
    struct timeval time_start;
    struct timeval time_end;

    size = atoi(argv[1]);
    num_threads = atoi(argv[2]);

    // create an array of p_threads
    pthread_t threads[num_threads];
    // store each thread ID
    int t_id[num_threads];
    // allocate memory to the grid (matrix)
    allocate_memory();
    // set grid initial conditions
    initialize_grid();

    double err = 1.0;
    int iter = 0;

    printf("Jacobi relaxation calculation: %d x %d grid\n", size, size);

    // get the start time
    gettimeofday(&time_start, NULL);

    // Jacobi iteration
    // This loop will end if either the maximum change reaches below a set threshold (convergence)
    // or a fixed number of maximum iterations have completed
    
    while (iter <= ITER_MAX) {
        for(int i=0;i<num_threads-1;i++){
            t_id[i] = i;
            pthread_create(&threads[i], NULL, calculate_grid, (void *) &t_id[i]);
        }

        if(iter % 100 == 0)

        iter++;
    }

    for(int i = 0; i < num_threads-1; i++){
        pthread_join(threads[i], NULL);
    }
    // get the end time
    gettimeofday(&time_end, NULL);

    double exec_time = (double) (time_end.tv_sec - time_start.tv_sec) +
                       (double) (time_end.tv_usec - time_start.tv_usec) / 1000000.0;

    //save the final grid in file
    save_grid();

    printf("\nKernel executed in %lf seconds with %d iterations and %d threads\n", exec_time, iter, num_threads);

    return 0;
}



void *calculate_grid(void *args){
    // calculates the Laplace equation to determine each cell's next value
    int id = *(int *) args;

    // calculate the chunk size
    int chunk = size / num_threads;

    // calcute begin and end step of the thread
    int begin = id * chunk;
    int end = begin + chunk;

    if( id == num_threads-1 ){
        end = size;
    }
    
        // kernel 1
    for(int i = begin+1; i <= end; i++) {

        for(int j = 1; j < size-1; j++) {
            new_grid[i][j] = 0.25 * (grid[i][j+1] + grid[i][j-1] +
                                         grid[i-1][j] + grid[i+1][j]);
            }
    }
    
    // copy the next values into the working array for the next iteration
    // kernel 2
    for(int i = begin+1; i <= end; i++) {
        for( int j = 1; j < size-1; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}