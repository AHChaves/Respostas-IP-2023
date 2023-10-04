#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "perfil.h"
#include "imprimeImg.h"


void Postar(perfil_s* perfil){

    perfil_s* conta;
    FILE* users;
    char url[URL_SIZE];
    int numUsers = NoOfUsers();
    int i = 0, numPostagem;
    bool find = false, imgValid;

    conta = (perfil_s*)malloc(numUsers * sizeof(perfil_s));

    users = fopen("users.txt", "rb");

    while(fread(&conta[i], sizeof(perfil_s), 1, users)){
        i++;
    }
    fclose(users);

    for(i = 0; i < numUsers; i++){
        if(strcmp(conta[i].id, perfil->id) == 0){

            find = true;

            numPostagem = conta[i].numPostagem;
            conta[i].postagem[numPostagem].id = numPostagem;

            printf("Informe o link da imagem: ");
            fgets(url, URL_SIZE, stdin);
            util_removeQuebraLinhaFinal(url);

            imgValid = PostaImg(&conta[i].postagem[numPostagem].img, url);
            
            if(imgValid){
                printf("Informe a descricao da postagem: ");
                fgets(conta[i].postagem[numPostagem].descricao, TAM_DESC, stdin);
                util_removeQuebraLinhaFinal(conta[i].postagem[numPostagem].descricao);
                conta[i].numPostagem++;
                conta[i].postagem = (postagem_s*)realloc(conta[i].postagem, sizeof(postagem_s) * (conta[i].numPostagem + 1))
            }
            memcpy(&(*perfil), &conta[i], sizeof(perfil_s));
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

void Apagar(perfil_s* perfil){

    int indice, i = 0, numUsers = NoOfUsers();
    perfil_s* perfils;
    FILE* users;
    bool valid = false;

    perfils = (perfil_s*)malloc(sizeof(perfil_s) * numUsers);
    users = fopen("users.txt", "rb");

    while (fread(&perfils[i], sizeof(perfil_s), 1, users))
    {
        i++;
    }
    fclose(users);
    
    printf("informe o indice da postagem que deseja apagar: ");
    scanf("%d", &indice);


    if((indice > 0) && (indice < (*perfil).numPostagem)){
        for(i = 0; i < numUsers; i++){
            if(strcmp(perfils[i].id, perfil->id) == 0){
                valid = true;
                //perfils[i].postagem[indice] = NULL;
                perfils[i].numPostagem--;
            }
        }
    }

    if(valid){
        users = fopen("users.txt", "wb");

        for(i = 0; i < numUsers; i++){
            fwrite(&perfils[i], sizeof(perfil_s), 1, users);
        }

        fclose(users);
    }
    else printf("postagem invalida!\n");

    free(perfils);
}

void ListarPostagens(perfil_s perfil){

    FILE* users;
    int  i;

    users = fopen("users.txt", "rb");

    for(i = 0; i< perfil.numPostagem; i++){
        printf("[%d]:\n%s", i, perfil.postagem[i].img->bytes);
    }

}