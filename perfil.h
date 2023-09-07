#define STRING_SIZE (100+1)

typedef struct perfil_t{
    char id[STRING_SIZE];
    char name[STRING_SIZE];
    char email[STRING_SIZE];
    char password[STRING_SIZE];
}perfil_s;

void util_removeQuebraLinhaFinal(char dados[]);

void AtribuiIDConta(perfil_s *perfil, int numPerfil);

void Email(perfil_s* perfil, int numPerfil);

void Cadastro(perfil_s* perfil, int numPerfil);

void Login(perfil_s* perfil);

void Listar(perfil_s* perfil);

void Busca(perfil_s* perfil);

void Visitar(perfil_s* perfil);