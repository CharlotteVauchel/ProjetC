#include "io.h"
#include <stdarg.h>

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
    printChar(valCara);
}

void printInteger(long long int val)
{
    long long int tmp = val;
    int cpt = 0;
    if(tmp>0) cpt++;
    while(tmp>10)
    {
        tmp = tmp/10;
        cpt++;
    }
    int tabVal[cpt];
    int tailleTab = cpt;
    while (val>0)
    {
        cpt--;
        int tmpVal = val%10;
        tabVal[cpt] = tmpVal;
        val = val/10;
    }

    for (int i = 0; i < tailleTab; i++)
    {
        printDigit(tabVal[i]);
    }
}

//TODO5
void newPrintf(char* chaine, ...)
{
    va_list args;
    va_start(args, chaine);

    while(*chaine != '\0')//Quand on atteint le caractère nul de la chaine, celle-ci est finie
    {
        while(*chaine != '%') //On affiche les caractères de la chaine tant que l'on ne tombe pas sur l'appel à un type
        {
            printChar(*chaine);
            ++chaine;
        }
        ++chaine; //On a croisé un % donc on regarde le caractère suivant
        if(*chaine == 'd')
        {
            int tmpVar = va_arg(args, int);
            printInteger(tmpVar);
        }else if (*chaine == 'c')
        {
            char tmpChar = va_arg(args, int);
            printChar(tmpChar);
        }else if (*chaine == 's')
        {
            char* tmpStr = va_arg(args, char*);
            printString(tmpStr);
        }
        ++chaine; 
    }
    va_end(args);
}