#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    BURBUJEO, SELECCION, INSERCION
} EMetodo;

typedef void (*nombre)(int n1,int n2);

typedef struct
{
    int* vec;     
    size_t ce;     
    size_t cap;     
    size_t tamElem; 
} Vector;

void tipoEnum(Vector* v, EMetodo opcion);
void ordenarBurbujeo(Vector* v);
void ordenarSeleccion(Vector* v);
void ordenarInsercion(Vector* v);
void intercambiar(int* n1, int* n2);

int main()
{
    Vector vec;
    vec.ce = 5;
    vec.cap = 5;
    vec.tamElem = sizeof(int);
    vec.vec = malloc(vec.cap * vec.tamElem);
    if (!vec.vec)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    int* datos = (int*)vec.vec; 
    datos[0] = 33;
    datos[1] = 13;
    datos[2] = 3;
    datos[3] = 45;
    datos[4] = 99;


    tipoEnum(&vec, INSERCION); 

    for (int i = 0; i < 5; i++)
    {
        printf("[%d]", datos[i]);
    }

    free(vec.vec);
    return 0;
}

void tipoEnum(Vector* v, EMetodo opcion)
{
    switch (opcion)
    {
    case BURBUJEO:
        ordenarBurbujeo(v);
        break;
    case SELECCION:
        ordenarSeleccion(v);
        break;
    case INSERCION:
        ordenarInsercion(v);
        break;
    }
}

void ordenarBurbujeo(Vector* v)
{
    int* ult = v->vec + (v->ce - 1);

    for(int i = 1, *limJ = ult - 1; i < v->ce; i++, limJ--)
    {
        for(int* j = v->vec; j <= limJ; j++)
        {
            if(*j > *(j + 1))
            {
                intercambiar(j, j + 1);
            }
        }
    }
}


void ordenarSeleccion(Vector* v)
{
    int* ult = v->vec + (v->ce - 1);
    int* m;

    for(int* i = v->vec; i < ult; i++)
    {
        m = i;
        for(int* j = i + 1; j <= ult; j++)
        {
            if(*j < *m)
            {
                m = j;
            }
        }

        intercambiar(m, i);
    }
}


void ordenarInsercion(Vector* v)
{
    int* ult = v->vec + (v->ce - 1);
    int* j;
    int elemAIns;

    for(int* i = v->vec + 1; i <= ult; i++)
    {
        elemAIns = *i;
        j = i - 1;
        while(j >= v->vec && elemAIns < *j)
        {
            *(j + 1) = *j;
            j--;
        }

        *(j + 1) = elemAIns;
    }
}

void intercambiar(int* n1, int* n2) {
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

