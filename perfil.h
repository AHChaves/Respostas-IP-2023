#define STRING_SIZE (100+1)

typedef struct perfil_t{
    char id[STRING_SIZE];
    char name[STRING_SIZE];
    char email[STRING_SIZE];
    char password[STRING_SIZE];
}perfil_s;

void util_removeQuebraLinhaFinal(char dados[]);

void SortPerfils(perfil_s* perfil, char** info);

int NoOfUsers();

void AtribuiIDConta(perfil_s* perfil);

void Email(perfil_s* perfil);

void Cadastro();

int Login(perfil_s perfil_logado);

void PrintInfos(perfil_s* perfil);

void FreeMatriz(char** matriz);

void EscolhaFiltragem(perfil_s* perfil);

void Listar();

void TrocaPosNoArray(perfil_s* perfils,int indiceInicio, int posTrocada);

void FiltraPerfis(perfil_s* perfils, char* procura);

void Buscar();

void Visitar(perfil_s* perfil);