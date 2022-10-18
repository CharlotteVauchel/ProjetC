#include "./lib/io.h"

int main()
{
    printChar('a');
    printString("\nBonjour\n");
    printDigit(3);
    printChar('\n');
    printInteger(85247923125976314);
    printChar('\n');
    newPrintf("L'entier vaut : %d, le charactère est : %c, et le string est : %s", 111, 'A', "hello");
    printChar('\n');
}