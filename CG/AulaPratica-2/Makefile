all: 
	$(exemplo3) $(coracao)
	
exemplo3:
	gcc exemplo3.c -o exemplo3 cg2d.o -lm -lX11
	./exemplo3
coracao:
	gcc exemplo3-coracao.c -o coracao cg2d.o -lm -lX11
	./coracao
clean:
	rm -rf coracao exemplo3