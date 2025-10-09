#include <stdio.h>
#include <stdlib.h>
#include "../VectorTDA/Vec.h"

int main()
{
    tVector v;
    tVector *vp;
    vp = &v;

    vectorCrear(vp);

    vectorOrdInsertar(vp, 1);
    vectorOrdInsertar(vp, 2);
    vectorOrdInsertar(vp, 3);
    vectorOrdInsertar(vp, 4);
    vectorInsertarAlInicio(vp, 0);
    vectorInsertarAlFinal(vp, 7);
    vectorInsertarEnPos(vp, 33, 2);

    int z = vectorEliminarElem(vp, 33);
    printf("\nEliminado: %d\n", z);

    vectorEliminarPrimero(vp);

    printf("Mostrar elementos\n");
    vectorMostrarElementos(vp);

    int j = vectorCantidadDeElementos(vp);
    printf("\nCantidad: %d\n", j);

    int elem;
    bool r = vectorObtenerDePos(vp, 4, &elem);
    printf("Encontrado: %d - valor: %d\n", r, elem);

    // printf("direccion: %p - contenido: %d\n", (void*)vp->vec, *(vp->vec));
    // printf("direccion: %p - contenido: %d\n", (void*)vp->vec+1, *(vp->vec+1));
}
