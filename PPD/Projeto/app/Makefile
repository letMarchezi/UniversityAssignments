CC=gcc

all: clean sequential openmp

sequential:
	$(CC) wave_seq.c -o wave_seq

openmp:
	$(CC) wave_omp.c -o wave_omp -fopenmp

clean:
	rm -f wave_seq wave_omp
	
	