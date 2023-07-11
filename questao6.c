#include <stdio.h> //importando in e out
#include <locale.h> //biblioteca de c que permite o uso de acentos no terminal

#define SUCESSO 0 //defindo SUCESSO

int main(int argc, char **argv){

    setlocale(LC_ALL, "Portuguese_Brazil"); //atribuicao da linguagem

    //Variaveis
    float num, den, result; //numerador, denominador e resultado da operacao

    //atribuindo o valor do numerador
    printf("Insira o valor do numerador:\t");
    scanf("%f",&num);

    //atribuindo o valor do denominador
    printf("Insira o valor do denominador:\t");
    scanf("%f",&den);

    //calculo que define o valor do resultado
    result = num / den;

    //imprime o numerador no resultado, depois o denominador e por fim o resultado (imprime sempre os valores atribuidos da esquerda para a direita)
    printf("O resultado de %.3f / %.3f é: %.3f\n", num, den, result);

    //Se chegou ate aqui eh porque deu tudo certo
    return SUCESSO;
}