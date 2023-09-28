#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "postagem.h"
#include "perfil.h"
#include "imprimeImg.h"

void Postar(char* perfil){

    perfil_s conta;
    FILE* users, temp;

    users = fopen("users.txt", "rb");
    temp = fopen("temp.txt", "wb");

    while(fread(&conta, sizeof(perfil_s), 1, users)){
        if(strcmp(conta.id, perfil) == 0){
            
            printf("Informe o link da imagem: ");
            fgets()

        }
        fwrite(&temp, sizeof(perfil_s), 1, temp);
    }

    

    fclose(users);
}