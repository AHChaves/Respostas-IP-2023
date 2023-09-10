#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "perfil.h"

void util_removeQuebraLinhaFinal(char dados[]) {
    int tamanho;
    tamanho = strlen(dados);
    if ((tamanho > 0) && (dados[tamanho - 1] == '\n')) {
        dados[tamanho - 1] = '\0';
    }
}

void SortPerfils(perfil_s* perfil, char** info){

    perfil_s swamp;
    char tmpInfo[STRING_SIZE], tmpNextInfo[STRING_SIZE];
    int i, j, tamId, tamNextId, menorTam;

    for(i = 0; i < (NoOfUsers() - 1); i++){
        strcpy(tmpInfo, info[i]);
        strcpy(tmpNextInfo, info[i+1]);

        tamId = strlen(tmpInfo);
        tamNextId = strlen(tmpNextInfo);

        for(j = 0; j < tamNextId; j++)
            tmpNextInfo[j] = tolower(tmpNextInfo[j]);

        for(j = 0; j < tamId; j++)
            tmpInfo[j] = tolower(tmpInfo[j]);   

        menorTam = (tamId > tamNextId) ? tamNextId : tamId;

        for(j = 0; j < menorTam; j++){
            if(tmpInfo[j] > tmpNextInfo[j]){
                swamp = perfil[i];
                perfil[i] = perfil[i+1];
                perfil[i+1] = swamp;
                break;
            }
            else if(tmpInfo[j] < tmpNextInfo[j])
                break;
        }
        
    }

}

int NoOfUsers(){

    FILE* users;
    int number;

    users = fopen("users.txt", "r");
    
    fseek(users, 0,SEEK_END);
    number = ftell(users)/sizeof(perfil_s);
    
    fclose(users);

    return number;
}

void AtribuiIDConta(perfil_s* perfil){
    
    FILE* listOfusers;
    perfil_s perfils;

    char tmpInfo[STRING_SIZE];
    bool usedID;

    listOfusers = fopen("users.txt", "r");

    do{
        usedID = false;

        printf("Digite o nome da conta: ");
        fgets(tmpInfo, STRING_SIZE, stdin);
        util_removeQuebraLinhaFinal(tmpInfo);

        while(fread(&perfils, sizeof(perfil_s),1, listOfusers)){
            if(strcmp(perfils.id, tmpInfo) == 0){
                usedID = true;
                break;
            }
        }

        if(usedID) printf("Nome da conta invalido!!\n");

    }while(usedID);

    fclose(listOfusers);

    strcpy(perfil->id, tmpInfo);
}

void Email(perfil_s* perfil){

    perfil_s perfils;
    FILE* listOfusers;

    listOfusers = fopen("users.txt", "r");

    int i, j;
    char tmpEmail[STRING_SIZE];
    bool validEmail = false, arrobaPresent, dotPresent, usedEmail;

    do{
        usedEmail = false;
        dotPresent = false;
        arrobaPresent = false;
        j = 0;
        printf("Digite um email: ");
        fgets(tmpEmail, STRING_SIZE, stdin);
        util_removeQuebraLinhaFinal(tmpEmail);

        for(i = 0; i < strlen(tmpEmail); i++){
            if(tmpEmail[i] == '@'){
                arrobaPresent = true;
                j=i;
            }
        }

        for(j; j < strlen(tmpEmail); j++){
            if(tmpEmail[j] == '.'){
                dotPresent = true;
            }
        }

        if(dotPresent && arrobaPresent){
            while(fread(&perfils, sizeof(perfil_s),1, listOfusers)){
                if(strcmp(tmpEmail, perfils.email) == 0 ){
                    usedEmail = true;
                    break;
                }
            }
        }
        else printf("Email invalido. Ele precisa ter um '@' e um dominio seguido de um '.'\n");

        if(dotPresent && arrobaPresent && !usedEmail){
            validEmail = true;
        }
        else if(dotPresent && arrobaPresent && usedEmail) printf("Email ja em uso!\n");
        
    }while(!validEmail);

    fclose(listOfusers);

    strcpy(perfil->email, tmpEmail);
}

void Cadastro(){
    
    FILE* users;

    perfil_s perfil;

    //perfil = (perfil_s*)calloc(1, sizeof(perfil_s));
    users = fopen("users.txt", "ab");

    AtribuiIDConta(&perfil);

    printf("Digite seu nome: ");
    fgets(perfil.name, STRING_SIZE, stdin);
    util_removeQuebraLinhaFinal(perfil.name);

    Email(&perfil);

    printf("informe uma senha para a conta: ");
    fgets(perfil.password, STRING_SIZE, stdin);
    util_removeQuebraLinhaFinal(perfil.password);

    fwrite(&perfil, sizeof(perfil_s), 1, users);

    //free(perfil);
    fclose(users);
}

int Login(perfil_s perfil_logado){

    FILE * users;
    perfil_s perfils;

    users = fopen("users.txt","rb");

    char idOuEmail[STRING_SIZE], senha[STRING_SIZE];
    int i = 0, indice;
    bool validId = false, validEmail = false;

    printf("Informe o nome ou email do perfil ao qual esta tentando logar: ");
    fgets(idOuEmail, STRING_SIZE, stdin);
    util_removeQuebraLinhaFinal(idOuEmail);

    while(fread(&perfils, sizeof(perfil_s), 1, users)){

        if(strcmp(idOuEmail, perfils.id) == 0){
            validId = true;
            indice = i;
            break;
        }
        if(strcmp(idOuEmail, perfils.email) == 0){
            validEmail = true;
            indice = i;
            break;
        }
        i++;
    }

    if(validEmail || validId) {
        printf("Informe a senha: ");
        fgets(senha, STRING_SIZE, stdin);
        util_removeQuebraLinhaFinal(senha);

        if(strcmp(senha, perfils.password) == 0){
            perfil_logado = perfils;
        }
        else printf("Senha invalida!\n");
    }
    else printf("Login invalido!\n");

    fclose(users);
}

void PrintInfos(perfil_s* perfil){
    printf("%-20s | %-50s | %-50s\n", "User", "Nome", "Email");

    for(int i = 0; i < NoOfUsers(); i++){
        printf("%-20s | %-50s | %-50s\n", perfil[i].id, perfil[i].name, perfil[i].email);
    }
}

void FreeMatriz(char** matriz){
    for(int i = 0; i < NoOfUsers(); i++){
        free(matriz[i]);
    }
    free(matriz);
}

void Listar(){

    perfil_s* perfil;
    FILE* users;
    int i = 0, opcao;
    char** sortMode;
    bool validOption = false;

    sortMode = (char**)malloc(sizeof(char*) * NoOfUsers());
    perfil = (perfil_s*)malloc(sizeof(perfil_s) * NoOfUsers());
    users = fopen("users.txt","rb");

    while(fread(&perfil[i], sizeof(perfil_s), 1, users)) {
        i++;
    }
    fclose(users);

    do{
        printf("Escolha uma opcao de listagem :\n1 - Id\n2 - Nome\n3 - Email\nopcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:{
            for(i = 0; i <NoOfUsers(); i++){
                sortMode[i] = (char*)malloc(sizeof(char) * STRING_SIZE);
                strcpy(sortMode[i], perfil[i].id);
            }

            SortPerfils(perfil, sortMode);
            PrintInfos(perfil);
            validOption = true;
            break;
        }
        case 2:{
            for(i = 0; i <NoOfUsers(); i++){
                sortMode[i] = (char*)malloc(sizeof(char) * STRING_SIZE);
                strcpy(sortMode[i], perfil[i].name);
            }

            SortPerfils(perfil, sortMode);
            PrintInfos(perfil);
            validOption = true;
            break;
        }
        case 3:{
            for(i = 0; i <NoOfUsers(); i++){
                sortMode[i] = (char*)malloc(sizeof(char) * STRING_SIZE);
                strcpy(sortMode[i], perfil[i].email);
            }

            SortPerfils(perfil, sortMode);
            PrintInfos(perfil);
            validOption = true;
            break;
        }
        default:{
            printf("Opcao invalida!!\n");
            break;
        }
        }
    }while(!validOption);
   
    FreeMatriz(sortMode);
    free(perfil);
}

void TrocaPosNoArray(perfil_s* perfils,int indiceInicio, int posTrocada){

    perfil_s swap;

    swap = perfils[indiceInicio];
    perfils[indiceInicio] = perfils[posTrocada];
    perfils[posTrocada] = swap;

}

void FiltraPerfis(perfil_s* perfils, char* procura){

    FILE* users;
    //perfil_s* tmpPerfils;
    int i, j, k, procuradoId, procuradoEmail, indiceInit= 0;

    char tmpID[STRING_SIZE], tmpEmail[STRING_SIZE];

    users = fopen("users.txt", "rb");


    for(i = 0; i < NoOfUsers(); i++){

        procuradoId = 0;
        procuradoEmail = 0;

        strcpy(tmpID, perfils[i].id);
        strcpy(tmpEmail, perfils[i].email);


        for(j = 0; j <strlen(procura); j++){
            procura[j] = tolower(procura[j]);

            for(k = 0; k < strlen(tmpID); k++){
                tmpID[k] = tolower(tmpID[k]);
                if(procura[j] == tmpID[k]){
                    procuradoId++;
                    break;
                }
            }

            for(k = 0; k < strlen(tmpEmail); k++){
                tmpEmail[k] = tolower(tmpEmail[k]);
                if(procura[j] == tmpEmail[k]){
                    procuradoEmail++;
                    break;
                }
            
            }
        }

        if(procuradoId == strlen(procura) || procuradoEmail == strlen(procura) ){
            if(indiceInit != i){
                TrocaPosNoArray(&perfils, indiceInit, i);
            }
            indiceInit++;
        }
        
    }

    perfils = (perfil_s*)realloc(perfils, sizeof(perfil_s) * indiceInit);
    
}

void Buscar(){

    FILE* users;
    perfil_s* perfil;
    char nomeOuEmail[STRING_SIZE];
    int i = 0;

    perfil = (perfil_s*)malloc(sizeof(perfil_s) * NoOfUsers());
    users = fopen("users.txt","rb");

    while(fread(&perfil[i], sizeof(perfil_s), 1, users)) {
        i++;
    }
    fclose(users);

    printf("Digite o nome ou email da conta desejada: ");
    fgets(nomeOuEmail, STRING_SIZE, stdin);

    FiltraPerfis(&perfil, nomeOuEmail);

}