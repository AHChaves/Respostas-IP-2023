#include <stdio.h> //importando in e out
#include <locale.h> //biblioteca de c que permite o uso de acentos no terminal

#define SUCESSO 0 //defindo SUCESSO

int main(int argc, char **argv){

    setlocale(LC_ALL, "Portuguese_Brazil"); //atribuição da linguagem

    //Variáveis
    float num1, num2, num3, num4, num5, num6, result; //numeros que vão ser somados e resultado da operaÃ§Ã£o

    //atribuindo valores aos numeros
    printf("Insira 6 valores para calcular a média aritimética (adicione espaços entre os numeros, ex: 1 2 3 ...):\n");
    scanf("%f %f %f %f %f %f",&num1, &num2, &num3, &num4, &num5, &num6);


    //calculo que define o valor do resultado
    result = (num1 + num2 + num3 + num4 + num5 + num6) / 6;

    //imprime a média aritimética
    printf("A média aritimética é: %f\n",  result);

    //Se chegou até aqui é porque deu tudo certo
    return SUCESSO;
}