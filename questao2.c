#include <stdio.h> //importando in e out
#include <locale.h> //biblioteca de c que permite o uso de acentos no terminal

#define SUCESSO 0 //defindo SUCESSO

int main(int argc, char **argv){

    setlocale(LC_ALL, "Portuguese_Brazil"); //atribuicao da linguagem

    //Variaveis
    int num1, num2, num3, num4, num5, result; //numeros que vao ser somados e resultado da operação

    //atribuindo valores aos numeros
    printf("Insira 5 valores que serão somados (adicione espaços entre os numeros, ex: 1 2 3 ...):\n");
    scanf("%d %d %d %d %d",&num1, &num2, &num3, &num4, &num5);

    //calculo que define o valor do resultado
    result = num1 + num2 + num3 + num4 + num5;

    //imprime o resultado da soma
    printf("O resultado da soma é: %d\n",  result);

    //Se chegou ate aqui eh porque deu tudo certo
    return SUCESSO;
}