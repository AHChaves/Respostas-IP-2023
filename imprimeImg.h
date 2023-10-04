#include <stdbool.h>
#include "structs.h"

asciiImg_t * insta_carregaImagem(char url[], bool colorido, int largura);

void insta_imprimeImagem(asciiImg_t * img);

void insta_liberaImagem(asciiImg_t * img);

bool PostaImg(asciiImg_t* img,char * url);