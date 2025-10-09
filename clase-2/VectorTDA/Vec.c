#include "Vec.h"

void vectorCrear(tVector *v)
{
    v->ce = 0;
}

int vectorOrdInsertar(tVector *v, int elem)
{
    if (v->ce == TAM)
        return LLENO;

    int *ult = v->vec + (v->ce - 1);
    int *i = v->vec;

    while (i <= ult && elem > *i)
    {
        i++;
    }

    if (i <= ult && elem == *i)
        return DUPLICADO;

    for (int *j = ult; j >= i; j--)
    {
        *(j + 1) = *j;
    }

    *i = elem;

    v->ce++;

    return TODO_OK;
}

int vectorOrdBuscar(const tVector *v, int elem)
{
    const int *li = v->vec;
    const int *ls = v->vec + (v->ce - 1);
    const int *m;
    int comp;
    bool encontrado = false;
    int ind = -1;

    while (!encontrado && li <= ls)
    {
        m = li + (ls - li) / 2;

        comp = elem - *m;

        if (comp < 0)
        {
            ls = m - 1;
        }
        else if (comp > 0)
        {
            li = m + 1;
        }
        else
        {
            encontrado = true;
            ind = m - v->vec;
        }
    }
    return ind;
}

bool vectorOrdEliminarElem(tVector *v, int elem)
{
    int pos = vectorOrdBuscar(v, elem);

    if (pos == -1)
    {
        return false;
    }

    return vectorEliminarDePos(v, pos);
}

bool vectorEliminarDePos(tVector *v, int pos)
{
    if (pos < 0 || pos >= v->ce)
    {
        return false;
    }

    int *ult = v->vec + (v->ce - 1);
    for (int *i = v->vec + pos + 1; i <= ult; i++)
    {
        *(i - 1) = *i;
    }

    v->ce--;

    return true;
}

int vectorInsertarAlInicio(tVector *v, int elem)
{
    if (v->ce == TAM)
    {
        return LLENO;
    }

    int *ult = v->vec + (v->ce - 1);
    int *ini = v->vec;

    while (ini < ult && *ini != elem)
    {
        ini++;
    }

    if (*ini == elem)
    {
        return DUPLICADO;
    }

    ini = v->vec;

    while (ult >= ini)
    {
        *(ult + 1) = *ult;
        ult--;
    }
    *(v->vec) = elem;
    v->ce++;
    return TODO_OK;
}

void vectorMostrarElementos(const tVector *v)
{
    const int *ult = v->vec + (v->ce - 1);
    for (const int *i = v->vec; i <= ult; i++)
    {
        printf("[%d]", *i);
    }
}

int vectorInsertarAlFinal(tVector *v, int elem)
{
    if (v->ce == TAM)
    {
        return LLENO;
    }

    int *ult = v->vec + (v->ce - 1);
    int *ini = v->vec;

    while (ini < ult && *ini != elem)
    {
        ini++;
    }

    if (*ini == elem)
    {
        return DUPLICADO;
    }

    *(ult + 1) = elem;
    v->ce++;
    return TODO_OK;
}

int vectorInsertarEnPos(tVector *v, int elem, int pos)
{
    if (v->ce == TAM)
    {
        return LLENO;
    }

    int *ult = v->vec + (v->ce - 1);
    int *ini = v->vec;
    int *ppos = v->vec + pos;
    int *i = ini;

    while (i < ult && *i != elem)
    {
        i++;
    }

    if (*i == elem)
    {
        return DUPLICADO;
    }

    while (ult >= ppos)
    {
        *(ult + 1) = *ult;
        ult--;
    }

    *ppos = elem;
    v->ce++;
    return TODO_OK;
}

int vectorBuscar(const tVector *v, int elem)
{
    const int *li = v->vec;
    const int *ls = v->vec + v->ce - 1;
    int encontrado = -1;

    while (li < ls && *li != elem)
    {
        li++;
    }

    if (*li == elem)
    {
        encontrado = li - v->vec;
    }

    return encontrado;
}

int vectorCantidadDeElementos(const tVector *v)
{
    return v->ce;
}

bool vectorEliminarElem(tVector *v, int elem)
{

    int pos = vectorBuscar(v, elem);

    if (pos == -1)
    {
        return false;
    }

    int *li = v->vec;
    int *ls = v->vec + v->ce - 1;
    int *ppos = v->vec + pos;

    if (ppos < li || ppos > ls)
    {
        return false;
    }

    while (ppos < ls)
    {
        *(ppos) = *(ppos + 1);
        ppos++;
    }

    v->ce--;

    return true;
}

bool vectorEliminarPrimero(tVector *v)
{
    if (v->ce < 1)
    {
        return false;
    }

    int *ls = v->vec + v->ce - 1;
    int *li = v->vec;

    while (li < ls)
    {
        *(li) = *(li + 1);
        li++;
    }

    v->ce--;
    return true;
}

bool vectorEliminarUltimo(tVector *v)
{
    if (v->ce < 1)
    {
        return false;
    }

    v->ce--;
    return true;
}

bool vectorVaciar(tVector *v)
{
    v->ce = 0;
    return true;
}

bool vectorObtenerDePos(const tVector *v, int pos, int *elem)
{
    const int *ppos = v->vec + pos;
    const int *li = v->vec;
    const int *ls = v->vec + v->ce - 1;

    if (ppos > ls || ppos < li)
    {
        *elem = -1;
        return false;
    }

    *elem = *ppos;
    return true;
}
