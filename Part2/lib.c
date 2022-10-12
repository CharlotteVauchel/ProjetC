#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{
    char expression1[50];
    char expression2[50];
    char operator;
}Commande;

void printWelcome(){
    printf("--------Bienvenue dans la calculatrice--------\n");
}

void printGoodbye(){
    printf("---------------A bientot !------------------\n");
}

void getInput(char input[], double *res){
    printf("Entrez votre expression (res = %f)\n", *res);
    fgets(input, sizeof(char)*100, stdin);
}

int isQuit(char input[]){
    char check[] = "quit";
    for(int i = 0; i < 4; i++){
        if(input[i] != check[i] ){
            return 0;
        }
    }
    return 1;
}

int getInputLength(char *input){
    int compt = 0;
    while(input[compt] != '\n'){
        compt++;
    }
    return compt;
}

void separateInput(Commande *commande, char *input, int length, double *resultat){
    int spaceIndex[2] = {0,0};
    int flag = 0;
    for(int i = 0; i < length; i++){
        if(input[i] == " "){
            assert(flag < 2);   //there should only be 2 spaces
            spaceIndex[flag] = i;
            flag ++;
        }
    }
    assert(spaceIndex[1]-spaceIndex[0] == 2); //the operator is one char

    for(int i = 0; i <= spaceIndex[0]; i++){
        commande->expression1[i] = input[i];
    }

    commande->operator = input[spaceIndex[0] + 1];
    for(int i = spaceIndex[1]+1; i <= length; i++){
        commande->expression2[i - (spaceIndex[1]+1)] = input[i];
    }
}

int isRes(char *exp){
    int check = 1;
    char res[] = {"res"};
        for(int i = 0; i < 3; i++){
        if(exp[i] != res[i]){
            check = 0;
        }
    }
    return check;
}

void getResult(Commande *commande, double *resultat){
    double leftExpression, rightExpression;
    if(isRes(commande->expression1)){
        leftExpression = *resultat;
    }
    else {
        //isFloat and isInt

    }
    if(isRes(commande->expression2)){
        rightExpression = *resultat;
    }
    else{
        //isFloat and isInt
    }


}

void calculate(char *input, double *resultat){
    int length = getInputLength(input);
    Commande *commande;

    separateInput(commande, input, length, resultat);
    getResult(commande, resultat);
}