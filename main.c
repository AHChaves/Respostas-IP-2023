#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STRING_SIZE (100+1)
#define SUCESSO 0 

void Fatorial() // faz o fatorial de um numero
{
    int i, num, fatorial;

    printf("Digite um número: ");
    scanf("%d", &num);

    for (i = 1; i < num; i++)
        fatorial = fatorial * i;

    printf("O fatorial de %d é %d!\n", num, fatorial);

} 

void ListaDeCompras(){

    int quantidade;
    char** item; //matriz de strings

    printf("Informe quantos itens deseja que a lista tenha: ");
    scanf("%d%*c", &quantidade); 

    item = (char**)malloc(sizeof(char*) * quantidade); //atribui o tamanho do string

    for(int i = 0; i < quantidade; i++){
        item = (char**)malloc(sizeof(char*) * STRING_SIZE); // atribui o tamanho da string
        printf("item %d: ", (i + 1));
        fgets(item[i], STRING_SIZE, stdin);
    }

    for(int i = 0; i < quantidade; i++){ //mostra o vetor de string
        printf("item n %d: %s", (i+1), item[i]);
    }

}

void CadastraNotas(){

    int numNotas, novoNumNotas, i;
    int* notas;
    bool valorValido = false;

    printf("Quantas notas serão distribuidas: ");
    scanf("%d", &numNotas);

    notas = (int*)malloc(sizeof(int) * numNotas); //atribui o tamanho do vetor de notas

    printf("Cadastre as notas de um aluno: \n");

    for(i = 0; i < numNotas; i++) { //atribui valor as notas
        printf("nota %d: ", (i+1));
        scanf("%d", &notas[i]);
    }

    do{
        printf("defina quantas notas serão cadastradas a mais(deve ser um valor maior do que o anterior): ");
        scanf("%d", &novoNumNotas);
        valorValido = novoNumNotas <= numNotas ? false : true; //operador ternario
    }while(!valorValido);

    notas = (int*)realloc(notas, sizeof(int) * novoNumNotas); //realoca o tamanho do vetor de notas

    printf("As notas cadastradas foram: \n");

    for(i = 0; i < (novoNumNotas - numNotas); i++) {
        printf("nota %d: ", (i+1));
        scanf("%d", &notas[i]);
    }

    for(i = 0; i <(novoNumNotas - numNotas); i++){ // imprime o vetor
        printf("nota %d: %d\n", i, notas[i]);
    }
}

int main(int argc, char **argv)
{

    int escolha;

    do
    {

        printf("================================\n");

        // Mostra as opcoes disponiveis
        printf("0 - Sair\n1 - fatorial\n2 - Lista de compras\n3 - notas\nEscolha:\t");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 0: break;
        case 1:
        {
            Fatorial();
            break;
        }
        case 2:
        {
            ListaDeCompras();
            break;
        }
        case 3:
        {
            CadastraNotas();
            break;
        }
        default:
        {
            printf("\nOpcao invalida!!!\n");
            break;
        }
        }

    } while (escolha != 0);

    return SUCESSO;
}