#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define CAP_INI 10

typedef struct{

int *vec;
size_t ce;
size_t cap;

}Vector;

bool vectorCrear(Vector *v);

#endif // MATRIZ_H_INCLUDED
