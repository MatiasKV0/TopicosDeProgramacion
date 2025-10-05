#include "Fecha.h"
#include <stdio.h>

// Funciones internas
int cantDiasMes(int m, int a);
bool esFechaValida(int d, int m, int a);
bool esBisiesto(int a);

// Primitivas:
//  - Siempre comienzan con el nombre del TDA (en este caso, 'Fecha').
//  - Forman la interfaz pública del tipo de dato.
//  - Pueden acceder directamente a los campos de la estructura.

void fechaSet(Fecha *f, int dia, int mes, int anio)
{
    f->dia = dia;
    f->mes = mes;
    f->anio = anio;
}

void fechaGet(const Fecha *f, int *d, int *m, int *a)
{
    *d = f->dia;
    *m = f->mes;
    *a = f->anio;
}

Fecha fechaSumarDias(const Fecha *f, int dias)
{
    Fecha fSuma = *f;

    fSuma.dia += dias;
    int cdm;

    while (fSuma.dia > (cdm = cantDiasMes(fSuma.mes, fSuma.anio)))
    {
        fSuma.dia -= cdm;
        fSuma.mes++;
        if (fSuma.mes > 12)
        {
            fSuma.mes = 1;
            fSuma.anio++;
        }
    }

    return fSuma;
}

int fechaDiferencia(const Fecha *f1, const Fecha *f2)
{
    Fecha fechaMayor, fechaMenor;

    if (f1->anio > f2->anio ||
        (f1->anio == f2->anio && f1->mes > f2->mes) ||
        (f1->anio == f2->anio && f1->mes == f2->mes && f1->dia > f2->dia))
    {
        fechaMayor = *f1;
        fechaMenor = *f2;
    }
    else
    {
        fechaMayor = *f2;
        fechaMenor = *f1;
    }

    int dias = 0;

    while (fechaMenor.anio < fechaMayor.anio ||
           fechaMenor.mes < fechaMayor.mes ||
           fechaMenor.dia < fechaMayor.dia)
    {
        fechaMenor = fechaSumarDias(&fechaMenor, 1);
        dias++;
    }
    return dias;
}

int fechaDiaDelAnio(const Fecha *f)
{
    int dias = f->dia;
    int cdm = 0;
    for (int m = 0; m < f->mes; m++)
    {
        if (m != 0)
        {
            cdm = cantDiasMes(m, f->anio);
            printf("Mes: %d - cantidad de dias: %d \n", m, cdm);
        }
        dias += cdm;
    }
    return dias;
}

// No primitivas:
//  - No acceden directamente a los campos del struct.
//  - Se implementan utilizando las primitivas, combinando su funcionalidad
//    para realizar operaciones más complejas o de nivel lógico sobre el TDA.

void ingresarFecha(Fecha *f)
{
    int d, m, a;
    printf("Ingrese dia: ");
    scanf("%d", &d);
    printf("Ingrese mes: ");
    scanf("%d", &m);
    printf("Ingrese anio: ");
    scanf("%d", &a);
    fechaSet(f, d, m, a);
    puts("Fecha registrada exitosamente");
}

void mostrarFecha(const Fecha *f){
    int d, m, a;

    fechaGet(f, &d, &m, &a);
    printf("Fecha: %02d/%02d/%04d\n", d, m, a);
}

int cantDiasMes(int m, int a)
{
    int diasMes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m == 2 && esBisiesto(a))
    {
        return 29;
    }

    return diasMes[m];
}

bool esFechaValida(int d, int m, int a)
{
    if (a < 1601)
    {
        return false;
    }

    if (m < 1 || m > 12)
    {
        return false;
    }

    if (d < 1 || d > cantDiasMes(m, a))
    {
        return false;
    }

    printf("Es una fecha valida!\n");
    return true;
}

bool esBisiesto(int a)
{
    return a % 4 == 0 && (a % 100 != 0 || a % 400 == 0);
}
