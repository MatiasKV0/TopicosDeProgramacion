#ifndef VEC_H_INCLUDED
#define VEC_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>

#define TAM 10
#define TODO_OK 0
#define LLENO 1
#define DUPLICADO 2

typedef struct
{
    int vec[TAM];
    size_t ce;
} tVector;

void vectorCrear(tVector *v);
int vectorOrdInsertar(tVector *v, int elem);
int vectorOrdBuscar(const tVector *v, int elem);
bool vectorOrdEliminarElem(tVector *v, int elem);
bool vectorEliminarDePos(tVector *v, int pos);
void vectorMostrarElementos(const tVector *v);
int vectorInsertarAlInicio(tVector *v, int elem);
int vectorInsertarAlFinal(tVector *v, int elem);
int vectorInsertarEnPos(tVector *v, int elem, int pos);
int vectorBuscar(const tVector *v, int elem);
int vectorCantidadDeElementos(const tVector *v);
bool vectorEliminarElem(tVector *v, int elem);
bool vectorEliminarPrimero(tVector *v);
bool vectorEliminarUltimo(tVector *v);
bool vectorVaciar(tVector *v);
bool vectorObtenerDePos(const tVector *v, int pos, int *elem);

#endif // VEC_H_INCLUDED
