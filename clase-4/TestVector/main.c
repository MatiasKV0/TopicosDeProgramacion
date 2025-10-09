#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "../Vector/vector.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Vector miVec;

    if (!vectorCrear(&miVec))
    {
        return SIN_MEM;
    }

    srand(time(NULL));

    for (int i = 1; i <= 100000; i++)
    {
        vectorOrdInsertarCDup(&miVec, rand());
    }

    vectorMostrar(&miVec);

    while (vectorCantidadDeElementos(&miVec) > 0)
    {
        vectorEliminarDePos(&miVec, 0);
    }

    vectorDestruir(&miVec);

    return 0;
}
