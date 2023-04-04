CC=gcc

all: clean mpi sequential openmp run

sequential:
	$(CC) vecadd_seq.c -o vecadd_seq

openmp:
	$(CC) vecadd_omp.c -o vecadd_omp -fopenmp

mpi:
	mpicc vecadd_mpi.c -O3 -o vecadd_mpi
run:
	mpirun -np 1 ./vecadd_mpi 9600000
	mpirun -np 2 ./vecadd_mpi 9600000
	mpirun -np 3 ./vecadd_mpi 9600000
	mpirun -np 4 ./vecadd_mpi 9600000
clean:
	rm -f vecadd_seq vecadd_omp vecadd_mpi
	