#include <stdio.h> //importando in e out
#include <locale.h> //biblioteca de c que permite o uso de acentos no terminal

#define SUCESSO 0 //defindo SUCESSO

int main(int argc, char **argv){

    setlocale(LC_ALL, "Portuguese_Brazil"); //atribuiï¿½ï¿½o da linguagem

    //Variaveis
    float salarioAtual, salarioNovo, percentual; 

    //atribui um valor a variavel salarioAtual
    printf("Insira o valor atual do salario:\t");
    scanf("%f", &salarioAtual);
    
    //atribui um valor a variavel salarioNovo
    printf("Insira o percentual de aumento do salario:\t");
    scanf("%f", &percentual);

    //atribui o valor atual do salario ao novo para podermos realizar o calculo
    salarioNovo = salarioAtual;

    //calculo que define o valor do novo salario
    salarioNovo += (salarioAtual * percentual)/100;

    //imprime o novo salario
    printf("O valor do salario após o aumento é: %0.2f\n",  salarioNovo);

    //Se chegou ate aqui eh porque deu tudo certo
    return SUCESSO;
}