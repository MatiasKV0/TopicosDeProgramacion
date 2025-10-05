#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../Fecha/Fecha.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Fecha f;

    ingresarFecha(&f);
    mostrarFecha(&f);
    putchar('\n');

    int dias=30;
    Fecha f1 = fechaSumarDias(&f, dias);
    printf("Fecha luego de sumar %d dias: ",dias);
    mostrarFecha(&f1);

    Fecha f2;
    ingresarFecha(&f2);

    printf("Diferencia entre fechas: %d dia(s)\n", fechaDiferencia(&f, &f2));

    printf("La cantidad de dias que van del año es: %d \n", fechaDiaDelAnio(&f));

    return 0;
}
