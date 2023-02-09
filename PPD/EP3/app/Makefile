CC=gcc

all: clean sequential openmp

sequential:
	$(CC) laplace_seq_iteracoes.c -o laplace_seq_it
openmp:
	$(CC) -fopenmp laplace_omp_iteracoes.c -o laplace_omp_it

clean:
	rm -f laplace_seq_it laplace_omp_it grid_laplace.txt grid_laplace_seq.txt
