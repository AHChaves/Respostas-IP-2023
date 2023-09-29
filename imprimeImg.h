#include <stdint.h>
#include <stdbool.h>

struct asciiImg_s {
  uint8_t* bytes;
  int nBytes;
};

/// Tipo "Imagem ASCII"
typedef struct asciiImg_s asciiImg_t;

asciiImg_t * insta_carregaImagem(char url[], bool colorido, int largura);

void insta_imprimeImagem(asciiImg_t * img);

void insta_liberaImagem(asciiImg_t * img);

int PostaImg(char * url);