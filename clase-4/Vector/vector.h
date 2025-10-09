#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdbool.h>

#define CAP_INI 10
#define FACTOR_INCR 1.5
#define FACTOR_DECR 0.5
#define FACTOR_OCUP 0.25

#define TODO_OK 0
#define LLENO 1
#define DUPLICADO 2
#define SIN_MEM 3


typedef struct
{
    int* vec;
    size_t ce;
    size_t cap;
}
Vector;


bool vectorCrear(Vector* v);
int vectorOrdInsertar(Vector* v, int elem);
int vectorOrdInsertarCDup(Vector* v, int elem);
int vectorInsertarAlIninio(Vector* v, int elem);
int vectorInsertarAlFinal(Vector* v, int elem);
int vectorInsertarEnPos(Vector* v, int elem, int pos);
int vectorOrdBuscar(const Vector* v, int elem);
int vectorBuscar(const Vector* v, int elem);
bool vectorOrdEliminarElem(Vector* v, int elem);
bool vectorEliminarElem(Vector* v, int elem);
bool vectorEliminarDePos(Vector* v, int pos);
bool vectorEliminarPrimero(Vector* v);
bool vectorEliminarUltimo(Vector* v);
size_t vectorCantidadDeElementos(const Vector* v);
void vectorVaciar(Vector* v);
bool vectorObtenerDePos(const Vector* v, int pos, int* elem);
void vectorMostrar(const Vector* v);
void vectorDestruir(Vector* v);


#endif // VECTOR_H
