#include <stdlib.h>
#include <stdio.h>
#include "vector.h"


bool redimensionarVector(Vector* v, float factor);


bool vectorCrear(Vector* v)
{
    v->ce = 0;

    v->vec = malloc(CAP_INI * sizeof(int));

    if(v->vec == NULL)
    {
        v->cap = 0;
        return false;
    }

    v->cap = CAP_INI;

    return true;
}


int vectorOrdInsertar(Vector* v, int elem)
{
    if(v->ce == v->cap)
    {
        if(!redimensionarVector(v, FACTOR_INCR))
        {
            return SIN_MEM;
        }
    }

    int* ult = v->vec + (v->ce - 1);
    int* i = v->vec;

    while(i <= ult && elem > *i)
    {
        i++;
    }

    if(i <= ult && elem == *i)
    {
        return DUPLICADO;
    }

    for(int* j = ult; j >= i; j--)
    {
        *(j + 1) = *j;
    }

    *i = elem;

    v->ce++;

    return TODO_OK;
}


int vectorOrdInsertarCDup(Vector* v, int elem)
{
    if(v->ce == v->cap)
    {
        if(!redimensionarVector(v, FACTOR_INCR))
        {
            return SIN_MEM;
        }
    }

    int* ult = v->vec + (v->ce - 1);
    int* i = v->vec;

    while(i <= ult && elem >= *i)
    {
        i++;
    }

    for(int* j = ult; j >= i; j--)
    {
        *(j + 1) = *j;
    }

    *i = elem;

    v->ce++;

    return TODO_OK;
}


int vectorOrdBuscar(const Vector* v, int elem)
{
    int* li = v->vec;
    int* ls = v->vec + (v->ce - 1);
    int* m;
    int comp;
    bool encontrado = false;
    int ind = -1;

    while(!encontrado && li <= ls)
    {
        m = li + (ls - li) / 2;

        comp = elem - *m;

        if(comp < 0)
        {
            ls = m - 1;
        }
        else if(comp > 0)
        {
            li = m + 1;
        }
        else
        {
            encontrado = true;
            ind = m - v->vec;
        }
    }

    return ind; // encontrado ? ind : -1;
}


bool vectorOrdEliminarElem(Vector* v, int elem)
{
    int pos = vectorOrdBuscar(v, elem);

    if(pos == -1)
    {
        return false;
    }

    return vectorEliminarDePos(v, pos);
}


bool vectorEliminarDePos(Vector* v, int pos)
{
    if(pos < 0 || pos >= v->ce)
    {
        return false;
    }

    int* ult = v->vec + (v->ce - 1);
    for(int* i = v->vec + pos + 1; i <= ult; i++)
    {
        *(i - 1) = *i;
    }

    v->ce--;

    if(((float)v->ce / v->cap) <= FACTOR_OCUP)
    {
        redimensionarVector(v, FACTOR_DECR);
    }

    return true;
}


size_t vectorCantidadDeElementos(const Vector* v)
{
    return v->ce;
}


void vectorVaciar(Vector* v)
{
    v->vec = realloc(v->vec, CAP_INI * sizeof(int));
    v->cap = CAP_INI;
    v->ce = 0;
}


void vectorMostrar(const Vector* v)
{
    int* ult = v->vec + (v->ce - 1);

    for(int* i = v->vec; i <= ult; i++)
    {
        printf("[%d]", *i);
    }

    putchar('\n');
}


void vectorDestruir(Vector* v)
{
    free(v->vec);
    v->vec = NULL;
    v->ce = 0;
    v->cap = 0;
}


bool redimensionarVector(Vector* v, float factor)
{
    size_t nuevaCap = v->cap * factor;
    
    if(nuevaCap < CAP_INI)
    {
        return true;
    }
    
    int* nuevoVec = realloc(v->vec, nuevaCap * sizeof(int));

    if(nuevoVec == NULL)
    {
        return false;
    }

    printf("Redimensión de %lld a %lld\n", v->cap, nuevaCap);

    v->vec = nuevoVec;
    v->cap = nuevaCap;

    return true;
}
