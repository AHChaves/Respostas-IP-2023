#include <stdio.h> //importando in e out
#include <locale.h> //biblioteca de c que permite o uso de acentos no terminal

#define SUCESSO 0 //defindo SUCESSO

int main(int argc, char **argv){

    setlocale(LC_ALL, "Portuguese_Brazil"); //atribuição da linguagem

    //Variavel
    float H; 

    //calculo que define o valor de H
    H = 1/1 + 1/2 + 1/3 + 1/4 + 1/5;

    //imprime H
    printf("O valor de H é: %0.2f\n",  H);

    //Se chegou ate aqui eh porque deu tudo certo
    return SUCESSO;
}