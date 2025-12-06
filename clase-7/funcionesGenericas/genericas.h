#ifndef GENERICAS_H_INCLUDED
#define GENERICAS_H_INCLUDED

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


typedef enum
{
    BURBUJEO, SELECCION, INSERCION
}
EMetodo;


typedef struct
{
    void* vec;
    size_t ce;
    size_t cap;
    size_t tamElem;
}
Vector;

/*
bool vectorCrear(Vector* v);
int vectorOrdInsertar(Vector* v, int elem);
int vectorOrdInsertarCDup(Vector* v, int elem);
int vectorInsertarAlIninio(Vector* v, int elem);
int vectorInsertarAlFinal(Vector* v, int elem);
int vectorInsertarEnPos(Vector* v, int elem, int pos);
int vectorOrdBuscar(const Vector* v, int elem);
int vectorBuscar(const Vector* v, int elem);
void vectorOrdenar(Vector* v, EMetodo metodo);
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
*/

typedef int (*Cmp)(const void* e1, const void* e2);
typedef void (*Accion)(void* e, void* dato);

bool vectorCrear(Vector* v, size_t tamElem);
int vectorInsertarAlFinal(Vector* v, const void* elem);
int vectorOrdInsertar(Vector* v, const void* elem);
void vectorRecorrer(Vector* v, Accion accion, void* dato);
int vectorOrdBuscar(const Vector* v, void* elem, Cmp cmp);


#endif // GENERICAS_H_INCLUDED
