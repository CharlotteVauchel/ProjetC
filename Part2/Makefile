all: libo compile

libo: 
	gcc -c lib.c -o lib.o
compile:
	gcc main.c lib.o -o a.out

run:
	./a.out

clean:
	rm *.o*