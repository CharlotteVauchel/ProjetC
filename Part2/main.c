/*
TODO finir getResult
Implementer printResultat
Implementer clear
*/


#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


int main(){
    double *resultat;
    resultat = (double*)malloc(sizeof(double));
    char input[100];
    //input = (char*)malloc(sizeof(char)* 100);
    printWelcome();
    do{
        getInput(input, resultat);
        calculate(input, resultat);
        //printResultat(input, resultat);
    }while(!isQuit(input));
    printGoodbye();

    free(resultat);
}