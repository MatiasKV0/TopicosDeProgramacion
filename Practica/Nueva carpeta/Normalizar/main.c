/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAM 50

#define esLetra(c) ((c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z'))
#define Mayuscula(c) (c >= 'A' && c <= 'Z') ? (c) : (c) - ('a'-'A')
#define Minuscula(c) (c >= 'a' && c <= 'z') ? (c) : (c) + ('a'-'A')

typedef struct
{
    char vPal[TAM];
} Palabra;

typedef struct
{
    char* cursor;
    bool finSec;
} SecPal;

void normalizarCadena(char* cadOrg,char* cadDest);
void PalabraNormalizada(Palabra* pal);

void secPalCrear(SecPal *sec, char *cad);
bool secPalLeer(SecPal *sec, Palabra *pal);
bool secPalEscribir(SecPal *sec, const Palabra *pal);
bool secPalEscribirCaracter(SecPal *sec, char c);
bool secPalFin(const SecPal *sec);
void secPalCerrar(SecPal *sec);


int main(int argc, char* argv[])
{

    char cadDest[TAM];

    normalizarCadena(argv[1],cadDest);

    printf("%s\n",cadDest);

    return 0;
}

void normalizarCadena(char* cadOrg,char* cadDest)
{
    SecPal leer,escribir;
    Palabra palabra;

    secPalCrear(&leer, cadOrg);
    secPalCrear(&escribir, cadDest);

    secPalLeer(&leer,&palabra);

    while(!secPalFin(&leer)){
        PalabraNormalizada(&palabra);
        secPalEscribir(&escribir,&palabra);
        if(secPalLeer(&leer,&palabra)){
            secPalEscribirCaracter(&escribir,' ');
        }
    }

    secPalCerrar(&escribir);
}

void PalabraNormalizada(Palabra *pal){
    char* i = pal->vPal;

    *i = Mayuscula(*i);
    i++;
    while(*i != '\0')
    {
        *i = Minuscula(*i);
        i++;
    }
}

void secPalCrear(SecPal *sec, char *cad){
    sec->cursor = cad;
    sec->finSec = false;
}

bool secPalLeer(SecPal *sec, Palabra *pal){
    while(*sec->cursor != '\0' && !esLetra(*sec->cursor)){
        sec->cursor++;
    }

    if(*sec->cursor == '\0'){
        sec->finSec = true;
        return false;
    }

    char* i = pal->vPal;

    while(*sec->cursor != '\0' && esLetra(*sec->cursor)){
        *i=*sec->cursor;
        i++;
        sec->cursor++;
    }

    *i = '\0';

    return true;
}

bool secPalEscribir(SecPal *sec, const Palabra *pal){

    const char *i = pal->vPal;

    while(*i != '\0'){
        *sec->cursor = *i;
        sec->cursor++;
        i++;
    }

    return true;
}

bool secPalEscribirCaracter(SecPal *sec, char c){
    *sec->cursor = c;
    sec->cursor++;
    return true;
}

void secPalCerrar(SecPal *sec){
    *sec->cursor = '\0';
}

bool secPalFin(const SecPal *sec){
    return sec->finSec;
}
*/
