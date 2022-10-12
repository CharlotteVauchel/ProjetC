all: libo compile

libo: 
	gcc -c lib.c -o lib.o
	nasm -f elf64 io.asm -o io.o
compile:
	gcc main.c io.o lib.o -o a.out

run:
	./a.out

clean:
	rm *.o*
