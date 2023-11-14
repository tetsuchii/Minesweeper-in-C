#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include "nullazas.h"
#include "palya.h"


void disztomb (Koord palya)
{
    int db=0;
    int meret=palya.x*palya.y;
    for (int i=0;i<meret;i++){
        printf(" + ");
        db++;
        if (db == palya.x){
            printf("\n");
            db=0;
        }
    }
}


void palya_feltolt (int **mezok, Koord palya)
{
    for (int i=0;i<palya.y;i++){
        for(int j=0;j<palya.x;j++){
            mezok[i][j] = 10;
        }
    }
}


void palya_kiir (Koord tipp, int **szamostomb, Koord palya, int** mezok)
{

    for (int i=0;i<palya.y;i++){
        for(int j=0;j<palya.x;j++){
            if (mezok[i][j] == 10)
                printf(" + ");
            else if ( mezok[i][j] == 12)
                printf(" F ");
            else
                printf(" %d ", szamostomb[i][j]);
            if(j==palya.x-1) printf("\n");
        }
    }
}

void felfedes (Koord tipp,int szamlalo, int **mezok, int **szamostomb, bool jatek, Koord palya)
{
    if (szamlalo == 9)
        jatek=false;
    if (szamlalo == 0)
        nullazas(tipp.x, tipp.y, mezok, szamostomb, palya);
    else
        mezok[tipp.y][tipp.x]=szamostomb[tipp.y][tipp.x];

}

