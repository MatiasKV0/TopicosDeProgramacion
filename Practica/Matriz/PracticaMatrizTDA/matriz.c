#include "matriz.h"

bool vectorCrear(Vector *v){
    v->ce=0;

    v->vec = malloc(sizeof(int) * CAP_INI);

    if(v->vec == NULL){
        v->cap=0;
        return false;
    }

    v->cap=CAP_INI;

    return true;
}
