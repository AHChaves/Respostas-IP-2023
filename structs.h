#define URL_CHAR_SIZE (500 + 1)
#define TAM_DESC (200+1)
#define STRING_SIZE (100+1)

typedef struct postagem_t{
    int id;
    char imagem[URL_CHAR_SIZE];
    char descricao[TAM_DESC];
}postagem_s;

typedef struct perfil_t{
    char id[STRING_SIZE];
    char name[STRING_SIZE];
    char email[STRING_SIZE];
    char password[STRING_SIZE];
    int numPostagem;
    postagem_s* postagem;
}perfil_s;