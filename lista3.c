#include <stdio.h>  // Biblioteca que exporta funcoes in e out
#include <locale.h> //Biblioteca que exporta as linguagens

#define SUCESSO 0 // Define Sucesso

void Questao1() {} // Roda a questao 1

void Questao2() {} // Roda a questao 2

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

        printf("================================\n");

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

            printf("\e[1;1H\e[2J");
            break;
        }
        case 2:
        {
            printf("\e[1;1H\e[2J");

            Questao2();

            printf("\e[1;1H\e[2J");
            break;
        }
        case 3:
        {
            printf("\e[1;1H\e[2J");

            Questao3();

            printf("\e[1;1H\e[2J");
            break;
        }
        case 4:
        {
            printf("\e[1;1H\e[2J");

            Questao4();

            printf("\e[1;1H\e[2J");
            break;
        }
        case 5:
        {
            printf("\e[1;1H\e[2J");

            Questao5();

            printf("\e[1;1H\e[2J");
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

            printf("\e[1;1H\e[2J");
            break;
        }
        default:
        {
            printf("\e[1;1H\e[2J");
            printf("\nOpção invalida!!!\n");
        }
        }

    } while (escolha != 0);

    return SUCESSO;
}