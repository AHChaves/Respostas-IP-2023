#include <stdio.h> //importando in e out
#include <locale.h> //biblioteca de c que permite o uso de acentos no terminal

#define SUCESSO 0 //defindo SUCESSO

int main(int argc, char **argv){

    setlocale(LC_ALL, "Portuguese_Brazil"); //atribuicao da linguagem

    //Variaveis
    int idade;
    char genero; 

    //atribui sua idade a variavel
    printf("Insira sua idade:\t");
    scanf("%d", &idade);

    //atribui o char a variavel
    printf("informe seu genero ('m' para masculino, 'f' para feminino):\t");
    scanf("%s", &genero);

    //Imprime a idade e a sigla do genero
    printf("Idade %d anos \ngenero: %c\n", idade, genero);

    //Se chegou ate aqui eh porque deu tudo certo
    return SUCESSO;
}