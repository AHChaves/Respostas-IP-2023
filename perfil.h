#include "postagem.h"

#define STRING_SIZE (100+1)

void util_removeQuebraLinhaFinal(char dados[]);

void SortPerfils(perfil_s* perfil, char** info, int inicio);

int NoOfUsers();

void AtribuiIDConta(perfil_s* perfil);

void Email(perfil_s* perfil);

void Cadastro();

void Login(char* perfil_logado, bool* logado);

void Deslogar(bool* logado);

void PrintInfos(perfil_s* perfil, int numUsers);

void FreeMatriz(char** matriz, int numUsers);

void EscolhaFiltragem(perfil_s* perfil, int init);

void Listar();

void TrocaPosNoArray(perfil_s* perfils,int indiceInicio, int posTrocada);

int FiltraPerfis(perfil_s* perfils, char* procura);

void Buscar();

void MostraUser(perfil_s perfils);

void Visitar(char* perfil);