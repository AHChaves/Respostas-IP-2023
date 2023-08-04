#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define SUCESSO 0
#define TamanhoNomeMax (100 + 1)
#define TamanhoCursoMax (50 + 1)
#define NumProvas 3

//Aqui eu crio uma struct e já renomeio ela para "dados_s"
typedef struct dado_s
{
    char nome[TamanhoNomeMax];
    char curso[TamanhoCursoMax];
    int matricula;
    float altura;
    float notas[NumProvas];
} dados_s;


void Leitura(dados_s *dados) //Func que recebe a struct dados (como um ponteiro, ou seja, um vetor) e grava informações nas variaveis dessa struct
{

    int i;

    printf("Informe seus dados:\n");

    getchar();//pega o "lixo" que pode atrapalhar o fgets

    printf("nome: ");
    fgets(dados->nome, TamanhoNomeMax, stdin); //atribui o que o usuario digitar para a variavel nome

    //essa "->" (setinha) substitui o "." para acessar dentro da struct, isso se torna necessario quando a struct é um ponteiro.
    //se a struct não fosse um ponteiro nessa situação poderia-se acessar a variavel dentro dela com um simples ".";    EX: dados.nome
    //pode-se tambem substituir a setinha "->" por (*dados).nome

    printf("curso: ");
    fgets(dados->curso, TamanhoCursoMax, stdin); //atribui o que o usuario digitar para a variavel curso

    printf("matricula: ");
    scanf("%d", &dados->matricula); //atribui a matricula

    printf("altura:");
    scanf("%f", &dados->altura); //atribui a altura

    printf("notas do Aluno: \n");

    for (i = 0; i < NumProvas; i++)
    {
        printf("Prova %d: ", (i + 1));
        scanf("%f", &dados->notas[i]); //grava todas as notas dos alunos
    }
}

float CalculoMedia(dados_s *dados) //realiza o calculo da media do aluno que esta na struct "n" recebida.
{

    int i;
    float soma = 0.0f;

    for (i = 0; i < NumProvas; i++)
    {
        soma += (dados->notas[i]);
    }

    return soma / NumProvas;
}

void Impressao(dados_s *dados) //imprime os valores condidos na struct
{

    int i;

    printf("Os dados do aluno sao: \n");
    printf("Nome: %s", dados->nome);
    printf("Curso: %s", dados->curso);
    printf("matricula: %d\n", dados->matricula);
    printf("altura: %0.2f", dados->altura);

    printf("\nAs notas do aluno foram: \n");
    for (i = 0; i < NumProvas; i++)
    {
        printf("Prova [%d]: %0.2f \n", (i + 1), dados->notas[i]);
    }

    printf("Media: %0.2f\n", CalculoMedia(dados));
}

void MetodoImpressao()//Funcao que define como vai ser impresso os dados dos alunos
{
    do
    {

        printf("Digite 1 para imprimir os dados de 1 aluno.\nDigite 2 para imprimir os dados de todos os alunos.\nDigite 0 para sair.\n");
        scanf("%d", &i);

        switch (i)
        {
        case 0:
            break;
        case 1:
        {
            printf("\e[1;1H\e[2J"); // printf que apaga o terminal

            printf("Digite o aluno que voce deseja ver a nota (digite de 0 ate %d): ", (NumAlunos - 1));
            scanf("%d", &num);

            Impressao(&dados[num]);

            break;
        }
        case 2:
        {
            printf("\e[1;1H\e[2J");

            for (i = 0; i < NumAlunos; i++)
            {
                Impressao(&dados[i]);
            }

            break;
        }
        default:
        {
            printf("\e[1;1H\e[2J");
            printf("\nOpção invalida!!!\n");
        }
        }

    } while (i != 0);
}

int main(int argc, char **argv)
{

    dados_s *dados; //cria um ponteiro da struct
    setlocale(LC_ALL, "");
    int i, num;
    int NumAlunos;
    float SomaTurma = 0.0f;

    printf("Digite o numero de alunos: ");
    scanf("%d", &NumAlunos); //descobre quantos alunos o usuario quer cadastrar

    dados = (dados_s *)malloc(sizeof(dados_s) * NumAlunos); //atribui quantas structs vão ter (um array)

    for (i = 0; i < NumAlunos; i++)
    {
        Leitura(&dados[i]); //para passar uma struct como um ponteiro é necessario o "&"
        printf("\e[1;1H\e[2J"); // printf que apaga o terminal
    }

    MetodoImpressao();

    free(dados);

    return SUCESSO;
}