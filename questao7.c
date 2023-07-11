#include <stdio.h> //importando in e out
#include <locale.h> //biblioteca de c que permite o uso de acentos no terminal

#define SUCESSO 0 //defindo SUCESSO

int main(int argc, char **argv){

    setlocale(LC_ALL, "Portuguese_Brazil"); //atribuicao da linguagem

    //Variaveis
    float notaA, notaB, notaC; 


    //atribuindo o valor das notas
    printf("Insira a nota de cada aluno em ordem (obs: coloque espaços entre as notas):\n");
    scanf("%f %f %f", &notaA, &notaB, &notaC);

    //imprime o numerador no resultado, depois o denominador e por fim o resultado (imprime sempre os valores atribuidos da esquerda para a direita)
    printf("aluno  |  nota  \n   a   |  %0.2f  \n   b   |  %0.2f  \n   c   |  %0.2f  ", notaA, notaB, notaC);

    //Se chegou ate aqui eh porque deu tudo certo
    return SUCESSO;
}