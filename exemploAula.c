#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define TAM_STRING (100+1)

typedef struct lista_t{
    char nome[TAM_STRING];
    int quantidade;
}lista_s;

void util_removeQuebraLinhaFinal(char dados[])
{ // funcao que remove o \n no final de strings
    int tamanho;
    tamanho = strlen(dados);
    if ((tamanho > 0) && (dados[tamanho - 1] == '\n'))
    {
        dados[tamanho - 1] = '\0';
    }
}

void Cadastro(lista_s * lista){

    printf("Informe o nome do produto: ");
    fgets(lista->nome, TAM_STRING, stdin);
    util_removeQuebraLinhaFinal(lista->nome);

    printf("informe a quantidade em unidades: ");
    scanf("%d", &lista->quantidade);
}

void Listar(lista_s * lista, int quantidade){

    int i;

    printf("%-50s | %-50s\n", "Nome", "Quantidade");

    for(i = 0; i < quantidade; i++){
        printf("%-50s | %-50d\n", lista->nome,lista->quantidade);
    }

}

int main(int argc, char ** argv){

    lista_s * lista;
    int posLista = 0, escolha;

    lista = (lista_s*)malloc(sizeof(lista_s) * posLista);

    do{

        printf("0 - Sair\n1 - Adicionar Item\n2 - Listar itens\nEscolha: ");
        scanf("%d%*c", &escolha);

        switch (escolha)
        {
        case 0: break;
        case 1: {
            Cadastro(&lista[posLista]);
            posLista++;
            lista = (lista_s*)realloc(lista, sizeof(lista_s) * posLista);
            break;
        }
        case 2: {
            Listar(lista, posLista);
            break;
        }
        default: {
            printf("Opcao invalida!!!\n");
            break;
        }
        }

    }while(escolha != 0);


    free(lista);
    return SUCESSO;
}