#ifndef STRUCTS_H
#define STRUCTS_H
#include <stdint.h>
#define TAM_DESC (200+1)
#define STRING_SIZE (100+1)

typedef struct asciiImg_s{
  uint8_t* bytes;
  int nBytes;
}asciiImg_t;

typedef struct postagem_t{
    int id;
    asciiImg_t* img;
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

#endif