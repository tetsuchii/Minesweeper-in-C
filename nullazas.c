#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"
#include "nullazas.h"
#include "palya.h"

void nullazas (int x, int y, int ** mezok, int** szamok, Koord palya)
{
        mezok[y][x]=szamok[y][y];
    if (palya.y>y-1 && 0<y-1){
        mezok[y-1][x]=szamok[y-1][x];
        if (mezok[y-1][x] == 0)
            nullazas(x,y-1,mezok,szamok,palya);}
    if (palya.y>y+1 && 0<y-1){
        mezok[y+1][x]=szamok[y+1][x];
        if (mezok[y+1][x] == 0)
            nullazas(x,y+1,mezok,szamok,palya);}
    if (palya.x>x-1 && 0<x-1){
        mezok[y][x-1]=szamok[y][x-1];
        if (mezok[y][x-1] == 0)
            nullazas(x-1,y,mezok,szamok,palya);}
    if (palya.x>x+1 && 0<x+1){
        mezok[y][x+1]=szamok[y][x+1];
        if (mezok[y][x+1] == 0)
            nullazas(x+1,y,mezok,szamok,palya);}

}
