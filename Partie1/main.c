#include "./lib/io.h"

//TODO6
//c generic function 
#define printG(val) _Generic((val), \
                    char: printChar, \
                    char *: printString, \
                    default: printInteger  \
              )(val)

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

    //TODO6 tests
    char c = 'c';
    int val = 4;
    int integ = 14;
    char * str = "bonjour";
    printG(c);
    printChar('\n');
    printG(val);
    printChar('\n');
    printG(14);
    printChar('\n');
    printG(str);
    printChar('\n');
}