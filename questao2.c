#include <stdio.h> //importando in e out
#include <locale.h> //biblioteca de c que permite o uso de acentos no terminal

#define SUCESSO 0 //defindo SUCESSO

int main(int argc, char **argv){

    setlocale(LC_ALL, "Portuguese_Brazil"); //atribuição da linguagem

    //Variáveis
    int num1, num2, num3, num4, num5, result; //numeros que vão ser somados e resultado da operação

    //atribuindo o valor do numerador
    printf("Insira 5 valores que ser�o somados:\n");
    scanf("%d %d %d %d %d",&num1, &num2, &num3, &num4, &num5);


    //calculo que define o valor do resultado
    result = num1 + num2 + num3 + num4 + num5;

    //imprime o resultado da soma
    printf("O resultado da soma �: %d\n",  result);

    //Se chegou até aqui é porque deu tudo certo
    return SUCESSO;
}