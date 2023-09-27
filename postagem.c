#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "postagem.h"
#include "perfil.h"
#include "imprimeImg.h"

void Postar(char* perfil){

    char url[URL_CHAR_SIZE];
    perfil_s conta;
    FILE* users;

    users = fopen("users.txt", "rb");

    while(fread(&conta, sizeof(perfil_s), 1, users)){
        if(strcmp(conta.id, perfil) == 0) break;
    }

    

    fclose(users);
}