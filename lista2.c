#include <stdio.h>  // Biblioteca que exporta funcoes in e out
#include <locale.h> //Biblioteca que exporta as linguagens

#define SUCESSO 0 // Define Sucesso

void Questao1() {// Roda a questao 1

    //Variaveis inteiras
    int numero1, numero2;

    //pede ao usuario para inserir o valor dos numeros
    printf("Insira os dois valores para a comparação (insira espaços entre os números): \n");
    scanf("%d %d",&numero1, &numero2); // atribui o valor inserido aos numeros

    printf("Resultado:\n");

    // se o numero 1 for maior que o numero 2, ele executo o comando dentro das chaves, se nao passa para a proxima condicional
    if(numero1 > numero2){
        printf("O numero %d é maior que o numero %d", numero1, numero2);
    }
    else if(numero1 == numero2){ //Se o numero 1 for igual ao numero, ele executa o comando dentro das chaves, se nao passa para a proxima condicional
        printf("O numero %d é igual ao numero %d", numero1, numero2);
    }
    else{ // Se nao passou por nenhuma condicional, o comando dentro das chaves sera executado
        printf("O numero %d é menor que o numero %d", numero1, numero2);
    }

} 

void Questao2() { // Roda a questao 2

    //Variaveis
    int num1, num2, num3, num4, num5, result;

    //atribui o valor as variaveis
    printf("Insira o valor dos 5 números:\n");
    scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);

    //atribui o valor da soma dos numeros a result
    result = num1 + num2 + num3 + num4 + num5;

    printf("O resultado da soma é: %d", result);
} 

void Questao3() {} // Roda a questao 3

void Questao4() {} // Roda a questao 4

void Questao5() {} // Roda a questao 5

void Questao6() {} // Roda a questao 6

void Questao7() {} // Roda a questao 7

int main(int argc, char **argv)
{

    setlocale(LC_ALL, ""); // atribui a linguagem para o codigo

    int escolha;

    do
    {

        printf("\n\n================================\n");

        // Mostra as opcoes disponiveis
        printf("Escolha uma das opções:\n[1] Questão 1\n[2] Questão 2\n[3] Questão 3\n[4] Questão 4\n[5] Questão 5\n[6] Questão 6\n[7] Questão 7\n[0] Fechar programa\nEscolha:\t");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 0:
            break;

        case 1:
        {
            printf("\e[1;1H\e[2J"); //printf que apaga o terminal

            Questao1(); //Chama a questao 1

            break;
        }
        case 2:
        {
            printf("\e[1;1H\e[2J");

            Questao2();

            break;
        }
        case 3:
        {
            printf("\e[1;1H\e[2J");

            Questao3();

            break;
        }
        case 4:
        {
            printf("\e[1;1H\e[2J");

            Questao4();

            break;
        }
        case 5:
        {
            printf("\e[1;1H\e[2J");

            Questao5();

            break;
        }
        case 6:
        {
            printf("\e[1;1H\e[2J");
            Questao6();
            break;
        }
        case 7:
        {
            printf("\e[1;1H\e[2J");

            Questao7();

            break;
        }
        default:
        {
            printf("\e[1;1H\e[2J");
            printf("\nOpÃ§ão invalida!!!\n");
        }
        }

    } while (escolha != 0);

    //apaga o terminal
    printf("\e[1;1H\e[2J");

    //Se chegou ate aqui eh porque deu tudo certo
    return SUCESSO;
}