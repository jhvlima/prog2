all: geraos main

main: main.o vetor.o
	gcc main.o vetor.o -o prog -lm

geraos: main.c vetor.c
	gcc -c main.c vetor.c

clean:
	rm -rf *.o prog output/*

run: main
	./prog <../input/test2D_1.txt >output/test2D_1.txt 
	./prog <../input/test2D_2.txt >output/test2D_2.txt 
	./prog <../input/test3D_1.txt >output/test3D_1.txt 
	./prog <../input/test3D_2.txt >output/test3D_2.txt 
