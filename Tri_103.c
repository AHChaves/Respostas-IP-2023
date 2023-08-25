#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SUCESSO 0
#define TAM_MAX_STRING (50 + 1)

typedef struct nota_t
{
    char atividade[TAM_MAX_STRING];
    float valor;
    float total;
} nota_s;

typedef struct aluno_t
{
    char nome[TAM_MAX_STRING];
    char curso[TAM_MAX_STRING];
    int matricula;
    int numAtividades;
    nota_s *notas;
} aluno_s;

void util_removeQuebraLinhaFinal(char dados[])
{ // funcao que remove o \n no final de strings
    int tamanho;
    tamanho = strlen(dados);
    if ((tamanho > 0) && (dados[tamanho - 1] == '\n'))
    {
        dados[tamanho - 1] = '\0';
    }
}

void FreeAlunos(aluno_s *alunos, int numAlunos)
{ // funcao que libera (free) alunos e notas

    int i;

    for (i = numAlunos; i > 0; i--)
    { // libera primeiro os notas presentes em cada alunos
        free(alunos[i].notas);
    }

    free(alunos); // depois libera alunos
}

void AdicionaAluno(aluno_s *aluno)
{

    aluno->numAtividades = 0;                            // define o numero de notas da aluno para 0
    aluno->notas = (nota_s *)malloc(sizeof(nota_s) * 1); // aloca dinamicamente notas para ter 1 de tamanho

    printf("Nome da aluno: ");
    fgets(aluno->nome, TAM_MAX_STRING, stdin);
    util_removeQuebraLinhaFinal(aluno->nome);

    printf("Curso da aluno: ");
    fgets(aluno->curso, TAM_MAX_STRING, stdin);
    util_removeQuebraLinhaFinal(aluno->curso);

    printf("Matricula da aluno: ");
    scanf("%d", &aluno->matricula);
}

int ProcuraAlunos(aluno_s *alunos, int numAlunos)
{ // funcao que procura uma alunos com base no matricula dela

    int i, procurado;

    printf("Informe o matricula da alunos desejado: ");
    scanf("%d", &procurado);

    for (i = 0; i < numAlunos; i++)
    {
        if (procurado == alunos[i].matricula)
        {
            return i; // retorna a posicao da alunos se o matricula informado pelo usuario for valido
        }
    }

    return -1; // se o matricula nao for valido retorna -1
}

void AdicionaAtividades(aluno_s *alunos)
{ // funcao que adiciona notas

    int escolha;
    float valorNota;
    bool notaValida;

    printf("Aluno: %s\n", alunos->nome);

    printf("Informe as atividades feitas pelo aluno.\n");

    do
    {
        notaValida = false;

        printf("0 - Sair\n1 - Adicionar Atividade\nEscolha: ");
        scanf("%d%*c", &escolha);

        switch (escolha)
        {

        case 0:
            break;

        case 1:
        {
            printf("Nome da Atividade: ");
            fgets(alunos->notas[alunos->numAtividades].atividade, TAM_MAX_STRING, stdin);
            util_removeQuebraLinhaFinal(alunos->notas[alunos->numAtividades].atividade);
            /*
             *  como eu ja recebo a posicao de alunos eu uso a "->"
             *  e informo que vou acessar notas na posiçao do numero de notas que é a posicao livre (sem nada informado)
             */

            printf("Insira o valor total da atividade: ");
            scanf("%f", &alunos->notas[alunos->numAtividades].total);

            do
            {
                printf("Insira a valor adquirido pelo aluno: ");
                scanf("%f", &valorNota);

                if (valorNota > alunos->notas[alunos->numAtividades].total)
                {
                    printf("Valor invalido!\nPor favor insira um valor valido.\n");
                }
                else
                {
                    alunos->notas[alunos->numAtividades].valor = valorNota;
                    notaValida = true;
                }
            } while (!notaValida);

            alunos->numAtividades++;// aumenta o numero de atividade no aluno
            alunos->notas = (nota_s *)realloc(alunos->notas, sizeof(nota_s) * (alunos->numAtividades + 1)); // aumento em 1 o tamnho do vetor de notas
            break;
        }
        default:
        {
            printf("Opcao invalida!!!\n");
            break;
        }
        }

    } while (escolha != 0);
}

void ListarAlunos(aluno_s *alunos, int numAlunos)
{ // funcao que lista todas as alunos em formato de tabela
    int i;

    printf("%-20s|%-20s|%-20s|%-20s\n", "Nome", "Curso", "Matricula", "Numero de atividades");

    for (i = 0; i < numAlunos; i++)
    {
        printf("%-20s|%-20s|%-20d|%-20d\n", alunos->nome, alunos->curso, alunos->matricula, alunos->numAtividades);
    }
}

void MostrarAlunos(aluno_s *alunos)
{ // funcao que informa os dados de uma alunos especifica
    int i;

    printf("Nome: %s\n", alunos->nome);
    printf("Cursp: %s\n", alunos->curso);
    printf("Matricula: %d\n", alunos->matricula);
    printf("Notas:\n");

    printf("%-20s|%-20s|%-20s\n", "Atividade", "Valor adquirido", "Total da atividade");

    for (i = 0; i < alunos->numAtividades; i++)
    {
        printf("%-20s|%-20f|%-20f\n", alunos->notas[i].atividade, alunos->notas[i].valor, alunos->notas[i].total);
    }
}

int main(int argc, char **argv)
{

    aluno_s *alunos;
    int escolha, numAlunos = 0, alunoProcurado;

    alunos = (aluno_s *)malloc(sizeof(aluno_s) * 1);

    do
    {

        printf("[0] Sair\n[1] Adicionar um aluno\n[2] Adicionar uma atividade ao aluno\n[3] Lista todos os alunos\n[4] Ver as notas de um aluno\nEscolha uma opcao: ");
        scanf("%d%*c", &escolha);

        switch (escolha)
        {

        case 0:
            break;
        case 1:
        {
            AdicionaAluno(&alunos[numAlunos]); // adiciono os dados da struct alunos
            numAlunos++;                       // aumento o numero maximo de alunos
            alunos = (aluno_s *)realloc(alunos, sizeof(aluno_s) * (numAlunos + 1));
            /*
             * aumento o tamanho do vetor de alunos para o numero maximo + 1,
             * o +1 eh para evitar que ele realoque para o mesmo tamanho
             */
            break;
        }
        case 2:
        {
            alunoProcurado = ProcuraAlunos(alunos, numAlunos); // o valor que for retornado da funcao Procuraalunos eh atribuido a alunoProcurado
            if (alunoProcurado == -1)
            { // se esse numero for igual a -1 o Matricula informado eh invalido
                printf("Matricula do aluno invalida!!!\n");
            }
            else
            {
                AdicionaAtividades(&alunos[alunoProcurado]); // se ele for diferente de -1 eh valido
            }
            break;
        }
        case 3:
        {
            ListarAlunos(alunos, numAlunos); // lista todas as alunoss
            break;
        }
        case 4:
        {
            alunoProcurado = ProcuraAlunos(alunos, numAlunos);
            if (alunoProcurado == -1)
            {
                printf("Matricula do aluno invalida!!!\n");
            }
            else
            {
                MostrarAlunos(&alunos[alunoProcurado]);
            }
            break;
        }
        default:
        {
            printf("Opcao invalida!!!\n");
            break;
        }
        }

    } while (escolha != 0);

    FreeAlunos(alunos, numAlunos);

    return SUCESSO;
}