#include "lib.h"

extern void putChar(int, char*,int);

int stringLength(char * chaine)
{
    int nbCara = 0;
    while (chaine[nbCara] != '\0')
    {
        nbCara++;
    }
    return nbCara;
}

void printChar(char cara)
{
    putChar(1, &cara, 1);
}

void printString (char * chaine)
{
    int nbCara = stringLength(chaine);
    for (int cpt = 0; cpt < nbCara; cpt++)
    {
        printChar(chaine[cpt]);
    }
}

//Print la valeur de l'int mais en char 0 = 48
void printDigit(int val)
{
    char valCara = val + '0';
}

void printInteger(int val)
{
    int cpt = 0;
    int tabVal[1000];
    while (val>0)
    {
        tabVal[cpt] = val%10;
        val = val/10;
        cpt++;
    }

    for (int i = 0; i >=0; i--)
    {
        printDigit(tabVal[i]);
    }
    
}