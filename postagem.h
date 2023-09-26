
typedef struct postagem_t{
    int id;
    char imagem[STRING_SIZE];
    char descricao[STRING_SIZE];
}postagem_s;

void Postar();

void Apagar();

void Editar();

void ListarPostagens(perfil_s perfil);

void Detalhar();