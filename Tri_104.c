#include <stdio.h>  
#include <string.h>
#include <stdlib.h> 
#include <locale.h> 
#define SUCESSO 0 
#define TAM_MAX_STRING (50+1)

typedef struct ingredientes_t { //struct de ingredientes
    char nome[TAM_MAX_STRING];
    float quantidade;
    int unidade;
}ingredientes_s;

typedef struct receitas_t { //struct de receitas
    char nome[TAM_MAX_STRING];
    char categoria[TAM_MAX_STRING];
    int codigo;
    int numIngredientes;
    ingredientes_s *ingredientes; //declaro um ponteiro de ingredientes dentro de receitas 
}receitas_s;

void util_removeQuebraLinhaFinal(char dados[]) { //funcao que remove o \n no final de strings
  int tamanho;
  tamanho = strlen(dados);
  if ((tamanho > 0) && (dados[tamanho - 1] == '\n')) {
    dados[tamanho - 1] = '\0';
  }
}

void FreeReceitas(receitas_s* receita, int numReceitas){ //funcao que libera (free) receitas e ingredientes

    int i;

    for(i = numReceitas; i > 0 ; i--){ //libera primeiro os ingredientes presentes em cada receita
        free(receita[i].ingredientes);
        
    }

    free(receita); //depois libera receitas
}

void AdicionaReceita(receitas_s * receita) { //funcao que adiciona uma receita a lista

    receita->numIngredientes = 0; //define o numero de ingredientes da receita para 0
    receita->ingredientes = (ingredientes_s *)malloc(sizeof(ingredientes_s) * 1); //aloca dinamicamente ingredientes para ter 1 de tamanho 

    printf("Nome da receita: ");
    fgets(receita->nome, TAM_MAX_STRING, stdin);
    util_removeQuebraLinhaFinal(receita->nome);

    printf("Categoria da receita: ");
    fgets(receita->categoria, TAM_MAX_STRING, stdin);
    util_removeQuebraLinhaFinal(receita->categoria);

    printf("Codigo da receita: ");
    scanf("%d", &receita->codigo);

}

int ProcuraReceita(receitas_s* receitas, int numReceitas) { //funcao que procura uma receita com base no codigo dela

    int i, procurado;

    printf("Informe o codigo da receita desejada: ");
    scanf("%d", &procurado);

    for(i = 0; i < numReceitas; i++){
        if(procurado == receitas[i].codigo){
            return i; //retorna a posicao da receita se o codigo informado pelo usuario for valido
        }
    }

    return -1; // se o codigo nao for valido retorna -1
}

void AdicionaIngrediente(receitas_s* receita) { // funcao que adiciona ingredientes
    
    int escolha;

    printf("%s", receita->nome);

    printf("Insira os ingredientes da receita.\n");

    do{
        printf("0 - Sair\n1 - Adicionar Ingrediente\nEscolha: ");
        scanf("%d%*c", &escolha);

        switch(escolha) {
        
        case 0: break;

        case 1: {
            printf("Nome do ingrediente: ");
            fgets(receita->ingredientes[receita->numIngredientes].nome, TAM_MAX_STRING, stdin); 
            util_removeQuebraLinhaFinal(receita->ingredientes[receita->numIngredientes].nome);
            /* 
            *  como eu ja recebo a posicao de receita eu uso a "->" 
            *  e informo que vou acessar ingredientes na posiçao do numero de ingredientes que é a posicao livre (sem nada informado)
            */

            printf("Insira a quantidade: ");
            scanf("%f", &receita->ingredientes[receita->numIngredientes].quantidade);

            printf("Insira quantas unidades: ");
            scanf("%d", &receita->ingredientes[receita->numIngredientes].unidade);

            receita->numIngredientes++; //aumenta a quantidade de ingredientes na receita
            receita->ingredientes = (ingredientes_s*)realloc(receita->ingredientes, sizeof(ingredientes_s) * (receita->numIngredientes + 1)); //aumento em 1 o tamnho do vetor de ingrdientes
            break;
        }
        default: {
            printf("Opcao invalida!!!\n");
            break;
        }
        }

    }while(escolha != 0);
}

void ListarReceitas(receitas_s* receita, int numReceitas) { //funcao que lista todas as receitas em formato de tabela
    int i;

    printf("%-20s|%-20s|%-20s|%-20s\n", "Nome", "Categoria", "Codigo", "Numero de Ingredientes");

    for(i=0; i<numReceitas; i++){
        printf("%-20s|%-20s|%-20d|%-20d\n", receita->nome, receita->categoria, receita->codigo, receita->numIngredientes);
    }
}

void MostrarReceita(receitas_s* receita){ //funcao que informa os dados de uma receita especifica
    int i;

    printf("Nome: %s\n", receita->nome);
    printf("Codigo: %s\n", receita->categoria);
    printf("Codigo: %d\n", receita->codigo);
    printf("Ingredientes:\n");

    printf("%-20s|%-20s|%-20s\n", "Nome", "Quantidade", "Unidades");

    for(i = 0; i < receita->numIngredientes; i++){
        printf("%-20s|%-20f|%-20d\n", receita->ingredientes[i].nome, receita->ingredientes[i].quantidade, receita->ingredientes[i].unidade);
    }

}

int main(int argc, char **argv)
{
    receitas_s* receita; //declaro a struct receitas
    int escolha, numReceitas = 0, receitaProcurada = -1;

    receita = (receitas_s*)malloc(sizeof(receitas_s) * 1);// defino o tamnho da struct receitas para 1

    do
    {

        printf("================================\n");

        // Mostra as opcoes disponiveis
        printf("Escolha uma das opcoes:\n[1] Cadastrar Receita\n[2] Cadastrar Ingrediente\n[3] Listar Receitas\n[4] Visualizar receita\n[0] Fechar programa\nEscolha:\t");
        scanf("%d%*c", &escolha);

        switch (escolha)
        {
        case 0:break;
        case 1:
        {
            AdicionaReceita(&receita[numReceitas]);// adiciono os dados da struct receitas
            numReceitas++; //aumento o numero maximo de receitas
            receita = (receitas_s*)realloc(receita, sizeof(receitas_s)*(numReceitas + 1)); 
            /*
            * aumento o tamanho do vetor de receitas para o numero maximo + 1,
            * o +1 eh para evitar que ele realoque para o mesmo tamanho
            */
            break;
        }
        case 2:
        {
            receitaProcurada = ProcuraReceita(receita, numReceitas); // o valor que for retornado da funcao ProcuraReceita eh atribuido a receitaProcurada
            if(receitaProcurada == -1){ // se esse numero for igual a -1 o codigo informado eh invalido
                printf("Codigo de receita invalido!!!\n");
            }else{
                AdicionaIngrediente(&receita[receitaProcurada]);//se ele for diferente de -1 eh valido
            }
            break;
        }
        case 3:
        {
            ListarReceitas(receita, numReceitas); //lista todas as receitas
            break;
        }
        case 4:
        {
            receitaProcurada = ProcuraReceita(receita, numReceitas);
            if(receitaProcurada == -1){
                printf("Codigo de receita invalido!!!\n");
            }else{
                MostrarReceita(&receita[receitaProcurada]);
            }
            break;
        }
        default:
        {
            printf("\nOpcao invalida!!!\n");
        }
        }

    } while (escolha != 0);


    FreeReceitas(receita, numReceitas);
    return SUCESSO;
}