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

void SortPerfils(perfil_s* perfil, char** info, int inicio){

    perfil_s swap;
    char tmpString[STRING_SIZE];
    int check, i, j, k, menorTam,tamInfo, tamNextInfo, numeroUsuarios = NoOfUsers();

    for(i = 0; i < inicio; i++){
        tamInfo = strlen(info[i]);
        for(j = 0; j <tamInfo; j++){
            info[i][j] = tolower(info[i][j]);
        }
    }

    for(i = 0; i < inicio; i++){

        tamInfo = strlen(info[i]);
        
        for(j = 0; j < inicio; j++){
            tamNextInfo = strlen(info[j]);

            menorTam = tamInfo >= tamNextInfo ? tamNextInfo : tamInfo;

            if(strcmp(info[i], info[j]) < 0){
                memcpy(&swap, &perfil[i], sizeof(perfil_s));memcpy(&swap, &perfil[i], sizeof(perfil_s));
                memcpy(&perfil[i], &perfil[j], sizeof(perfil_s));
                memcpy(&perfil[j], &swap, sizeof(perfil_s));
                strcpy(tmpString, info[i]);
                strcpy(info[i], info[j]);
                strcpy(info[j], tmpString);
            }
        }
    }    
}

int NoOfUsers(){

    FILE* users;
    int number;

    users = fopen("users.txt", "rb");
    
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

    listOfusers = fopen("users.txt", "rb");

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

    listOfusers = fopen("users.txt", "rb");

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

    users = fopen("users.txt", "ab");

    perfil.numPostagem = 0;
    perfil.postagem = (postagem_s*)malloc(1 * sizeof(postagem_s));


    AtribuiIDConta(&perfil);

    printf("Digite seu nome: ");
    fgets(perfil.name, STRING_SIZE, stdin);
    util_removeQuebraLinhaFinal(perfil.name);

    Email(&perfil);

    printf("informe uma senha para a conta: ");
    fgets(perfil.password, STRING_SIZE, stdin);
    util_removeQuebraLinhaFinal(perfil.password);

    fwrite(&perfil, sizeof(perfil_s), 1, users);

    fclose(users);
}

void Login(char *perfil_logado, bool *logado){

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
            strcpy(perfil_logado, perfils.id);
            *logado = true;
        }
        else printf("Senha invalida!\n");
    }
    else printf("Login invalido!\n");

    fclose(users);
}

void Deslogar(bool *logado){
    *logado = false;
}

void PrintInfos(perfil_s* perfil, int numUsers){
    printf("%-20s | %-50s | %-50s\n", "User", "Nome", "Email");

    for(int i = 0; i < numUsers; i++){
        printf("%-20s | %-50s | %-50s\n", perfil[i].id, perfil[i].name, perfil[i].email);
    }
}

void FreeMatriz(char** matriz, int numUsers){
    for(int i = 0; i < numUsers; i++){
        free(matriz[i]);
    }
    free(matriz);
}

void EscolhaFiltragem(perfil_s* perfil, int numUsers){

    int i = 0, opcao;
    char** sortMode;
    bool validOption = false;

    sortMode = (char**)malloc( sizeof(char*) * numUsers);

    do{
        printf("Escolha uma opcao de listagem :\n1 - Id\n2 - Nome\n3 - Email\nopcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:{
            for(i = 0; i < numUsers; i++){
                sortMode[i] = (char*)malloc(sizeof(char) * STRING_SIZE);
                strcpy(sortMode[i], perfil[i].id);
            }

            SortPerfils(perfil, sortMode, numUsers);
            PrintInfos(perfil, numUsers);
            validOption = true;
            break;
        }
        case 2:{
            for(i = 0; i < numUsers; i++){
                sortMode[i] = (char*)malloc(sizeof(char) * STRING_SIZE);
                strcpy(sortMode[i], perfil[i].name);
            }

            SortPerfils(perfil, sortMode, numUsers);
            PrintInfos(perfil , numUsers);
            validOption = true;
            break;
        }
        case 3:{
            for(i = 0; i < numUsers; i++){
                sortMode[i] = (char*)malloc(sizeof(char) * STRING_SIZE);
                strcpy(sortMode[i], perfil[i].email);
            }

            SortPerfils(perfil, sortMode, numUsers);
            PrintInfos(perfil , numUsers);
            validOption = true;
            break;
        }
        default:{
            printf("Opcao invalida!!\n");
            break;
        }
        }
    }while(!validOption);
   
    FreeMatriz(sortMode, numUsers);

}

void Listar(){

    perfil_s* perfil;
    FILE* users;
    int i = 0;


    perfil = (perfil_s*)malloc(sizeof(perfil_s) * NoOfUsers());
    users = fopen("users.txt","rb");

    while(fread(&perfil[i], sizeof(perfil_s), 1, users)) {
        i++;
    }
    fclose(users);

    EscolhaFiltragem(perfil, NoOfUsers());
    
    free(perfil);
    
}

int FiltraPerfis(perfil_s* perfils, char* procura){

    perfil_s swap;

    int i, j, k, procuradoId, procuradoEmail, tamanho = 0;

    char* emailtmp;

    char tmpID[STRING_SIZE], tmpEmail[STRING_SIZE];

    for(i = 0; i < NoOfUsers(); i++){

        procuradoId = 0;
        procuradoEmail = 0;

        strcpy(tmpID, perfils[i].id);
        strcpy(tmpEmail, perfils[i].email);

        emailtmp = strtok(tmpEmail, "@");

        printf("%s", emailtmp);

        for(j = 0; j < strlen(procura); j++){
            procura[j] = tolower(procura[j]);

            for(k = 0; k < strlen(tmpID); k++){
                tmpID[k] = tolower(tmpID[k]);
                if(procura[j] == tmpID[k]){
                    procuradoId++;
                    break;
                }
            }

            for(k = 0; k < strlen(emailtmp); k++){
                tmpEmail[k] = tolower(emailtmp[k]);
                if(procura[j] == emailtmp[k]){
                    procuradoEmail++;
                    break;
                }
            
            }
        }

        if(procuradoId == strlen(procura) || procuradoEmail == strlen(procura) ){
            swap = perfils[tamanho];
            perfils[tamanho] = perfils[i];
            perfils[i] = swap;
            tamanho++;
        }
        
    }
    
    return tamanho;
}

void Buscar(){

    FILE* users;
    perfil_s* perfil;
    char nomeOuEmail[STRING_SIZE];
    int i = 0, init;

    perfil = (perfil_s*)malloc(sizeof(perfil_s) * NoOfUsers());
    users = fopen("users.txt","rb");

    while(fread(&perfil[i], sizeof(perfil_s), 1, users)) {
        i++;
    }
    fclose(users);

    printf("Digite o nome ou email da conta desejada: ");
    fgets(nomeOuEmail, STRING_SIZE, stdin);
    util_removeQuebraLinhaFinal(nomeOuEmail);

    init = FiltraPerfis(perfil, nomeOuEmail);

    EscolhaFiltragem(perfil, init);

    free(perfil);
}

void MostraUser(perfil_s perfil){

    printf("%s\n%s\n", perfil.id, perfil.email);

}

void Visitar(char* perfil){

    char nomePerfil[STRING_SIZE];
    int i = 0,  indice;
    perfil_s perfils;
    bool validId = false, validEmail = false;

    FILE* users;

    users = fopen("users.txt", "rb");

    printf("informe o nome do perfilque deseja acessar: ");
    fgets(nomePerfil, STRING_SIZE, stdin);
    util_removeQuebraLinhaFinal(nomePerfil);

    while(fread(&perfils, sizeof(perfil_s), 1, users)){
        if(strcmp(nomePerfil, perfils.id) == 0){
            strcpy(perfil, perfils.id);
            MostraUser(perfils);
            validId = true;
            break;
        }
    }

    if(!validId){
        printf("O usuario não existe!\n");
    }

}