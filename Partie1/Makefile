all: libo compile run clean

libo: 
	gcc -c ./lib/io.c -o ./lib/io.o
	nasm -f elf64 ./ASM/io.asm -o ./ASM/io.o
compile:
	gcc main.c ./lib/io.o ./ASM/io.o -o a.out

run:
	clear
	./a.out

clean:
	rm *.o*