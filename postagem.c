#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "perfil.h"
#include "imprimeImg.h"


void Postar(char* perfil){

    perfil_s* conta;
    FILE* users;
    int numUsers = NoOfUsers();
    int i = 0, numPostagem;
    bool find = false;

    conta = (perfil_s*)malloc(numUsers * sizeof(perfil_s));

    users = fopen("users.txt", "rb");

    while(fread(&conta[i], sizeof(perfil_s), 1, users)){
        i++;
    }
    fclose(users);

    for(i = 0; i < numUsers; i++){
        if(strcmp(conta[i].id, perfil) == 0){

            find = true;

            numPostagem = conta[i].numPostagem;
            conta[i].postagem[numPostagem].id = numPostagem;

            printf("Informe o link da imagem: ");
            fgets(conta[i].postagem[numPostagem].imagem, URL_CHAR_SIZE, stdin);
            util_removeQuebraLinhaFinal(conta[i].postagem[numPostagem].imagem);

            printf("Informe a descricao da postagem: ");
            fgets(conta[i].postagem[numPostagem].descricao, TAM_DESC, stdin);
            util_removeQuebraLinhaFinal(conta[i].postagem[numPostagem].descricao);

            PostaImg(conta[i].postagem[numPostagem].imagem);
            
            conta[i].numPostagem++;
        }
    }


    if(find){
        users = fopen("users.txt", "wb");

        for(i = 0; i < numUsers; i++){
            fwrite(&conta[i], sizeof(perfil_s), 1, users);
        }

        fclose(users);
    }

    free(conta);
}