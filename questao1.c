#include <stdio.h> //importando in e out
#include <locale.h> //biblioteca de c que permite o uso de acentos no terminal

#define SUCESSO 0 //defindo SUCESSO

int main(int argc, char **argv){

    setlocale(LC_ALL, "Portuguese_Brazil"); //atribui��o da linguagem

    //Vari�veis
    int num, den, result; //numerador, denominador e resultado da opera��o

    //atribuindo o valor do numerador
    printf("Insira o valor do numerador:\t");
    scanf("%d",&num);

    //atribuindo o valor do denominador
    printf("Insira o valor do denominador:\t");
    scanf("%d",&den);

    //calculo que define o valor do resultado
    result = num / den;

    //imprime o numerador no resultado, depois o denominador e por fim o resultado (imprime sempre os valores atribuidos da esquerda para a direita)
    printf("O resultado de %d / %d �: %d\n", num, den, result);

    //Se chegou at� aqui � porque deu tudo certo
    return SUCESSO;
}