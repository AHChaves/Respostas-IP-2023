#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "perfil.h"

void util_removeQuebraLinhaFinal(char dados[]) { //funcao que remove o \n no final de strings
  int tamanho;
  tamanho = strlen(dados);
  if ((tamanho > 0) && (dados[tamanho - 1] == '\n')) {
    dados[tamanho - 1] = '\0';
  }
}

void AtribuiIDConta(perfil_s* perfil, int numPerfil){

    char tmpID[STRING_SIZE];
    bool usedID = false;

    do{

        getchar();
        printf("Digite o nome da conta: ");
        fgets(tmpID, STRING_SIZE, stdin);

        for(int i = 0; i < numPerfil; i++){
            if(strcmp(perfil[i].id, tmpID) == 0){
                usedID = true;
                break;
            }
        }

        if(usedID) printf("Nome da conta invalido!!\n");

    }while(!usedID);

    strcpy(perfil[numPerfil].id, tmpID);
}

void Email(perfil_s* perfil, int numPerfil){

    int i, j;
    char tmpEmail[STRING_SIZE];
    bool validEmail = false, arrobaPresent = false, dotPresent = false, usedEmail = false;

    do{
        j = 0;

        getchar();
        printf("Digite um email: ");
        fgets(tmpEmail, STRING_SIZE, stdin);
        util_removeQuebraLinhaFinal(tmpEmail);

        for(i = 0; i < strlen(tmpEmail); i++){
            arrobaPresent = tmpEmail[i] == '@' ? true: false;
            j++;
        }

        for(i = j; i < strlen(tmpEmail); i++)
            dotPresent = tmpEmail[i] == '.' ? true : false;

        if(dotPresent && arrobaPresent){
            for(i = 0; i < numPerfil; i++){
                if(strcmp(tmpEmail, perfil[i].email) == 0 ){
                    usedEmail = true;
                    break;
                }
            }
        }
        else printf("Email invalido. Ele precisa ter um '@' e um dominio seguido de um '.'\n");

        if(dotPresent && arrobaPresent && !usedEmail){
            validEmail = true;
        }
        else if(dotPresent && arrobaPresent && !usedEmail) printf("Email ja em uso!\n");
        
    }while(!validEmail);

    strcpy(perfil[numPerfil].email, tmpEmail);
}

void Cadastro(perfil_s* perfil, int numPerfil){
    
    AtribuiIDConta(perfil, numPerfil);

    getchar();
    printf("Digite seu nome: ");
    fgets(perfil[numPerfil].name, STRING_SIZE, stdin);
    util_removeQuebraLinhaFinal(perfil[numPerfil].name);

    Email(perfil, numPerfil);

    printf("informe uma senha para a conta: ");
    fgets(perfil[numPerfil].password, STRING_SIZE, stdin);

}

void Login(perfil_s* perfil, int numPerfil){

    char idOuEmail[STRING_SIZE], senha[STRING_SIZE];
    int i, indice;
    bool validId = false, validEmail = false, validPassword = false;

    printf("Informe o nome ou email do perfil ao qual esta tentando logar: ");
    scanf("%d",&idOuEmail);

    for(i = 0; i <numPerfil; i++){
        if(strcmp(idOuEmail, perfil[i].id) == 0){
            validId = true;
            indice = i;
        }
    }
    
    for(i = 0; i < numPerfil; i++){
        if(strcmp(idOuEmail, perfil[i].email) == 0){
            validEmail = true;
            indice = i;
        }
    }

    if(validEmail || validId) {
        printf("Informe a senha: ");
        fgets(senha, STRING_SIZE, stdin);
        if(strcmp(senha, perfil[indice].password) == 0){
            validPassword = true;
        }
        else printf("Senha invalida!\n");
    }
    else printf("Login invalido!\n");
}