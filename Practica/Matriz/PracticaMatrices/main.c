#include "../PracticaMatrizTDA/matriz.h"
#include <stdlib.h>
#include <time.h>

#define FIL 3
#define COL 4

void** crearMatriz(int filas, int columnas, size_t tamElem);
void destruirMatriz(void** m, int filas);
void llenarMatriz(int** m, int filas, int columnas);
void imprimirMatriz(int** m, int filas, int columnas);
void sumarDiagonalMatriz(int** m,int filas,int columnas);
void sumarDiagonalSecundariaMatriz(int** m,int filas,int columnas);
void sumarTrianInDP(int** m, int filas, int columnas);
void sumarTrianSuDS(int** m,int filas, int columnas);

int main()
{
    srand(time(NULL));


    int** m = (int**)crearMatriz(FIL,COL,sizeof(int));

    if(!m){
        printf("Error en la creacion.\n");
        return 1;
    }

    llenarMatriz(m,FIL,COL);

    imprimirMatriz(m,FIL,COL);

    sumarDiagonalMatriz(m,FIL,COL);

    sumarDiagonalSecundariaMatriz(m,FIL,COL);

    sumarTrianInDP(m,FIL,COL);

    sumarTrianSuDS(m,FIL,COL);

    destruirMatriz((void**)m,FIL);

    return 0;
}

void** crearMatriz(int filas, int columnas, size_t tamElem){

    void** m = malloc(filas * sizeof(void*));

    if(!m){
        return NULL;
    }

    void** ult = m + (filas - 1);

    for(void** i = m; i <= ult; i++){
        *i = malloc(columnas*tamElem);
        if(!*i){
            destruirMatriz(m,i-m);
            return NULL;
        }
    }

    return m;
}

void llenarMatriz(int** m, int filas, int columnas){

    for(int i = 0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            m[i][j]=rand()%10 + 1;
        }
    }

}

void imprimirMatriz(int** m, int filas, int columnas){
        for(int i = 0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            printf("%03d ",m[i][j]);
        }
        printf("\n");
    }
}

void sumarDiagonalMatriz(int** m,int filas,int columnas){

    int menor = (filas<=columnas) ? filas : columnas;
    int suma = 0;

    for(int i = 0; i < menor; i++){
        suma += m[i][i];
    }

    printf("Total %d\n",suma);
}

void sumarDiagonalSecundariaMatriz(int** m,int filas,int columnas){

    int menor = (filas<=columnas) ? filas : columnas;
    int suma = 0;

    for(int i = 0; i < menor; i++){
        suma += m[i][columnas - i - 1];
    }

    printf("Total %d\n",suma);
}

void sumarTrianInDP(int** m, int filas, int columnas){

    int suma = 0;

    for(int i = 1; i < filas; i++){
        for(int j = 0;j < i; j++){
            suma += m[i][j];
        }
    }

    printf("Suma TriInDP: %d\n",suma);

}

void sumarTrianSuDS(int** m,int filas, int columnas){

    int suma = 0;

    if(filas>=columnas){
        for(int i = 0; i < filas-1; i++){
            for(int j = 0;j < columnas-i-1; j++){
                suma += m[i][j];
            }
        }
    }
    else{
        for(int i = 0; i < filas; i++){
            for(int j = 0;j < columnas-i-1; j++){
                suma += m[i][j];
            }
        }
    }

    printf("Suma TriSuDS: %d\n",suma);
}

void destruirMatriz(void** m, int filas){
    void** ult = m + (filas - 1);

    for(void** i = m; i <= ult; i++){
        free(*i);
    }

    free(m);
}
