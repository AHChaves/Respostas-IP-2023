#include <stdio.h>
#include <time.h>
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
    char* tmpId, *tmpNextId;
    int i, j, tamId, tamNextId, menorTam;

    for(i = 0; i < (NoOfUsers() - 1); i++){
        strcpy(tmpId, info[i]);
        strcpy(tmpNextId, info[i+1]);

        tamId = strlen(tmpId);
        tamNextId = strlen(tmpNextId);

        for(j = 0; j < tamNextId; j++)
            tmpNextId[j] = tolower(tmpNextId[j]);

        for(j = 0; j < tamId; j++)
            tmpId[j] = tolower(tmpId[j]);

        menorTam = tamId > tamNextId ? tamNextId : tamId;

        for(j = 0; j < menorTam; j++){
            if(tmpId[j] > tmpNextId[j]){
                swamp = perfil[i];
                perfil[i] = perfil[i+1];
                perfil[i+1] = swamp;
                break;
            }
            else if(tmpId[j] < tmpNextId[j])
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

void AtribuiIDConta(perfil_s perfil, FILE* users){

    perfil_s perfils;


    char tmpID[STRING_SIZE];
    bool usedID = false;

    do{

        getchar();
        printf("Digite o nome da conta: ");
        fgets(tmpID, STRING_SIZE, stdin);

        while(fread(&perfils, sizeof(perfil_s),1, users)){
            if(strcmp(perfils.id, tmpID) == 0){
                usedID = true;
                break;
            }

        }

        if(usedID) printf("Nome da conta invalido!!\n");

    }while(!usedID);

    strcpy(perfil.id, tmpID);
}

void Email(perfil_s perfil, FILE* users){

    perfil_s perfils;

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
            while(fread(&perfils, sizeof(perfil_s),1, users)){
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
        else if(dotPresent && arrobaPresent && !usedEmail) printf("Email ja em uso!\n");
        
    }while(!validEmail);

    strcpy(perfil.email, tmpEmail);
}

void Cadastro(){
    
    FILE* users;

    perfil_s perfil;

    users = fopen("users.txt", "a");

    AtribuiIDConta(perfil, users);

    getchar();
    printf("Digite seu nome: ");
    fgets(perfil.name, STRING_SIZE, stdin);
    util_removeQuebraLinhaFinal(perfil.name);

    Email(perfil, users);

    printf("informe uma senha para a conta: ");
    fgets(perfil.password, STRING_SIZE, stdin);

    fwrite(&perfil, sizeof(perfil_s), 1, users);

    fclose(users);

}

int Login(perfil_s perfil_logado){

    FILE * users;
    perfil_s perfils;

    users = fopen("users.txt","r");

    char idOuEmail[STRING_SIZE], senha[STRING_SIZE];
    int i, indice;
    bool validId = false, validEmail = false;

    printf("Informe o nome ou email do perfil ao qual esta tentando logar: ");
    scanf("%d",&idOuEmail);
    while(!validEmail || !validId || fread(&perfils, sizeof(perfil_s), 1, users) ){

        if(strcmp(idOuEmail, perfils.id) == 0){
            validId = true;
            indice = i;
        }
        if(strcmp(idOuEmail, perfils.email) == 0){
            validEmail = true;
            indice = i;
        }
        
    }

    if(validEmail || validId) {
        printf("Informe a senha: ");
        fgets(senha, STRING_SIZE, stdin);
        if(strcmp(senha, perfils.password) == 0){
            perfil_logado = perfils;
        }
        else printf("Senha invalida!\n");
    }
    else printf("Login invalido!\n");

    fclose(users);
}

void PrintInfos(perfil_s* perfil){
    printf("%-20s | %-50s | %-50s", "User", "Nome", "Email");

    for(int i = 0; i < NoOfUsers; i++){
        printf("%-20s | %-50s | %-50s", perfil[i].id, perfil[i].name, perfil[i].email);
    }
}

void Listar(){

    FILE* users;
    perfil_s* perfil;
    int i = 0, opcao;
    char* sortMode[STRING_SIZE];
    bool validOption = false;

    users = fopen("users.txt","r");

    while(fread(&perfil[i], sizeof(perfil_s),1, users)) {
        i++;
    }

    do{
        printf("Escolha uma opcao de listagem :\n1 - Id\n2 - Nome\n3 - Email\nopcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:{
            for(i = 0; i <NoOfUsers; i++)
                strcpy(sortMode[i], perfil[i].id);

            SortPerfils(perfil, sortMode);
            PrintInfos(perfil);
            validOption = true;
            break;
        }
        case 2:{
            for(i = 0; i <NoOfUsers; i++)
                strcpy(sortMode[i], perfil[i].name);

            SortPerfils(perfil, sortMode);
            PrintInfos(perfil);
            validOption = true;
            break;
        }
        case 3:{
            for(i = 0; i <NoOfUsers; i++)
                strcpy(sortMode[i], perfil[i].email);

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
   
    fclose(users);
}