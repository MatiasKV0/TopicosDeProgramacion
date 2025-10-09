#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "../Vector/vector.h"


int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Vector miVec;

    if(!vectorCrear(&miVec))
    {
        return SIN_MEM;
    }

    srand(time(NULL));

    for(int i = 1; i <= 100000; i++)
    {
        vectorInsertarAlFinal(&miVec, rand());
    }

    time_t segIni = time(NULL);

    vectorOrdenar(&miVec, INSERCION);

    time_t segFin = time(NULL);

//    vectorMostrar(&miVec);

    printf("El ordenamiento tardó %lld segundos\n", segFin - segIni);
    fflush(stdout);
    
    vectorDestruir(&miVec);

    return 0;
}
