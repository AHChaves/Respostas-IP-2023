#include <stdio.h> 
#include <stdbool.h>
#include "perfil.h"

#define SUCESSO 0 

bool file_exists(const char *filename)
{
    FILE * fp = fopen(filename, "r");
    bool file_exist = false;
    if (fp != NULL)
    {
        file_exist = true;
        fclose(fp); // close the file
    }
    return file_exist;
}

int main(int argc, char **argv)
{
    FILE* users;
    perfil_s perfilLogado;
    int opcao;

    if (!file_exists("users.txt")){
        users = fopen("users.txt", "w");
        fclose(users);
    }

    do{

        printf("0 - Sair\n1 - Adicionar Usuario\n2 - Logar\n3 - Listar usuarios\nEscolha: ");
        scanf("%d%*c", &opcao);

        switch (opcao)
        {
        case 0: break;
        case 1: {
            Cadastro();
            break;
        }
        case 2: {
            Login(perfilLogado);
            break;
        }
        case 3: {
            Listar();
            break;
        }
        default: {
            printf("Opcao Invalida!!!\n");
            break;
        }
        }

    }while(opcao != 0);

    return SUCESSO;
}