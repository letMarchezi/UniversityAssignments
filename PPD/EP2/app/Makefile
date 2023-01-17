CC=gcc

all: clean sequential pthread

sequential:
	$(CC) laplace_seq_iteracoes.c -o laplace_seq_it

pthread:
	$(CC) laplace_pth_iteracoes.c -o laplace_pth_it -lpthread
clean:
	rm -f laplace_seq_it laplace_pth_it grid_laplace.txt
