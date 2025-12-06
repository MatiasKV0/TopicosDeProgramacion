#include <stdio.h>
#include <string.h>

typedef struct{

    int cod;
    char nom[10];
    char tipo;

}Datos;

int main()
{

    Datos datos,datos1;
    char nomArch[50] = "datos.txt";

    FILE *arch = fopen(nomArch,"w+t");

    datos.cod = 1;
    strcpy(datos.nom,"Matias");
    datos.tipo = 'A';

    fprintf(arch,"%2d-%10s-%c",datos.cod,datos.nom,datos.tipo);

    rewind(arch);

    fscanf(arch,"%2d-%10s-%c",&datos1.cod,&datos1.nom,&datos1.tipo);

    printf("%d   %s   %c",datos1.cod,datos1.nom,datos1.tipo);

    fclose(arch);

    return 0;
}
