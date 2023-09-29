#include <stdio.h> 
#include <stdbool.h>
#include "perfil.h"

#define SUCESSO 0 

bool file_exists(const char *filename)
{
    FILE * fp = fopen(filename, "rb");
    bool file_exist = false;
    if (fp != NULL)
    {
        file_exist = true;
        fclose(fp); // close the file
    }
    return file_exist;
}

void UnLogged(int* opcao, char* perfilLogado, char* visitado, bool* logado ){
    printf("0 - Sair\n1 - Adicionar Usuario\n2 - Logar\n3 - Listar usuarios\n4 - Buscar\n5 - Visualizar perfil\nEscolha: ");
    scanf("%d%*c", &*opcao);

    switch (*opcao)
    {
    case 0: break;
    case 1: {
        Cadastro();
        break;
    }
    case 2: {
        Login(perfilLogado, logado);
        break;
    }
    case 3: {
        Listar();
        break;
    }
    case 4: {
        Buscar();
        break;
    }
    case 5: {
        Visitar(visitado);
        break;
    }
    default: {
        printf("Opcao Invalida!!!\n");
        break;
    }
    }

}

void Logged(char* perfil, char* visitado, bool* logado, int *opcao){

    printf("0 - Sair\n1 - Deslogar\n2 - Buscar\n3 - Visualizar perfil\n4 - Postar\nEscolha: ");
    scanf("%d%*c", &*opcao);

    switch (*opcao)
    {
    case 0 : break;
    case 1: {
        Deslogar(logado);
        break;
    }
    case 2: {
        Buscar();
        break;
    }
    case 3: {
        Visitar(visitado);
        break;
    }
    case 4: {
        Postar(perfil);
        break;
    }
    case 5: {
        break;
    }
    default: {
        printf("Opcao Invalida!!!\n");
        break;
    }
    }

}

int main(int argc, char **argv)
{
    FILE* users;
    char perfilLogado[STRING_SIZE], visitado[STRING_SIZE];
    int opcao;
    bool logado = false;

    if (!file_exists("users.txt")){
        users = fopen("users.txt", "wb");
        fclose(users);
    }

    do{
        if(!logado){
            UnLogged(&opcao, perfilLogado, visitado, &logado);
        }
        else{
            Logged(perfilLogado, visitado, &logado, &opcao);
        }
    }while(opcao != 0);

    return SUCESSO;
}