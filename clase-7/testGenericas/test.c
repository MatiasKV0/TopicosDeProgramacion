#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "../Vector/vector.h"
#include "../Fecha/Fecha.h"


int cmpFecha(const void* e1, const void* e2);
void printFecha(void* e, void* dato);


int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Vector miVec;

    if(!vectorCrear(&miVec, sizeof(Fecha)))
    {
        return SIN_MEM;
    }

//    srand(time(NULL));

    Fecha f = {1, 10, 2025};

    for(int i = 10; i >= 1; i--)
    {
        f.dia = i;
        vectorOrdInsertar(&miVec, &f, cmpFecha);
    }
/*
    time_t segIni = time(NULL);

    vectorOrdenar(&miVec, INSERCION);

    time_t segFin = time(NULL);
*/
    vectorMostrar(&miVec);
    vectorRecorrer(&miVec, printFecha, NULL);
/*
    printf("El ordenamiento tardó %lld segundos\n", segFin - segIni);
    fflush(stdout);
*/
    vectorDestruir(&miVec);

    return 0;
}


int cmpFecha(const void* e1, const void* e2)
{
    const Fecha* f1 = e1;
    const Fecha* f2 = e2;

    return (f1->anio * 10000 + f1->mes * 100 + f1->dia) - (f2->anio * 10000 + f2->mes * 100 + f2->dia); // 20251004
}


void printFecha(void* e, void* dato)
{
    Fecha* f = e;

    printf("%d/%d/%d\n", f->dia, f->mes, f->anio);
}
