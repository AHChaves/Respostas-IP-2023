#include <stdio.h>
#include <locale.h>

#define SUCESSO 0

int main(int argc,char **argv){

    //Define a liguagem do codigo para porugues, dessa forma poderemos usar acentos nos printfs
    setlocale( LC_ALL, "Portuguese_Brazil");

    //Variaveis inteiras
    int numero1, numero2;

    //pede ao usuario para inserir o valor dos numeros
    printf("Insira os dois valores para a comparação (insira espaços entre os números): \n");
    scanf("%d %d",&numero1, &numero2); // atribui o valor inserido aos numeros

    // se o numero 1 for maior que o numero 2, ele executo o comando dentro das chaves, se não passa para a proxima condicional
    if(numero1 > numero2){
        printf("O numero %d é maior que o numero %d", numero1, numero2);
    }
    else if(numero1 == numero2){ //Se o numero 1 for igual ao numero, ele executa o comando dentro das chaves, se não passa para a proxima condicional
        printf("O numero %d é igual ao numero %d", numero1, numero2);
    }
    else{ // Se não passou por nenhuma condicional, o comando dentro das chaves sera executado
        printf("O numero %d é menor que o numero %d", numero1, numero2);
    }


    // Se chegou ate aqui é porque deu tudo certo
    return SUCESSO;
}