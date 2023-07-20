all:
	gcc -c cg2d.c --common
	gcc -c cg3d.c --common
	gcc prisma1.c -o prisma1 cg2d.o cg3d.o -lm -lX11
	gcc prisma2.c -o prisma2 cg2d.o cg3d.o -lm -lX11
	gcc prisma3.c -o prisma3 cg2d.o cg3d.o -lm -lX11
	gcc prisma4.c -o prisma4 cg2d.o cg3d.o -lm -lX11		
	#gcc teapot.c -o teapot cg2d.o cg3d.o -lm -lX11
	
