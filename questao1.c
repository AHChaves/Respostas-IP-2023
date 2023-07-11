#include <stdio.h> //importando in e out
#include <locale.h> //biblioteca de c que permite o uso de acentos no terminal

#define SUCESSO 0 //defindo SUCESSO

int main(int argc, char **argv){

    setlocale(LC_ALL, "Portuguese_Brazil"); //atribuição da linguagem

    //Variáveis
    int num, den, result; //numerador, denominador e resultado da operação

    //atribuindo o valor do numerador
    printf("Insira o valor do numerador:\t");
    scanf("%d",&num);

    //atribuindo o valor do denominador
    printf("Insira o valor do denominador:\t");
    scanf("%d",&den);

    //calculo que define o valor do resultado
    result = num / den;

    //imprime o numerador no resultado, depois o denominador e por fim o resultado (imprime sempre os valores atribuidos da esquerda para a direita)
    printf("O resultado de %d / %d é: %d\n", num, den, result);

    //Se chegou até aqui é porque deu tudo certo
    return SUCESSO;
}