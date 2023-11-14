#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "nullazas.h"

bool marletezik (Koord *bomba, int hanyadik)
{
    for (int i=0;i<hanyadik;i++){
        if (bomba[hanyadik].x == bomba[i].x && bomba[hanyadik].y == bomba[i].y )
            return true;
    }
    return false;
}

bool elsotipp (Koord *bomba, int hanyadik, Koord tipp, Koord palya)
{
    for (int i=0;i<hanyadik;i++){
        if (bomba[hanyadik].x == tipp.x && bomba[hanyadik].y == tipp.y )
                return true;
        if (palya.x>tipp.x-1 && 0<tipp.x-1){
            if (bomba[hanyadik].x == tipp.x-1 && bomba[hanyadik].y == tipp.y)
                return true;}
        if (palya.y>tipp.y-1 && 0<tipp.y-1){
            if (bomba[hanyadik].x == tipp.x && bomba[hanyadik].y == tipp.y-1)
                return true;}
        if (palya.x>tipp.x+1 && 0<tipp.x+1){
            if (bomba[hanyadik].x == tipp.x+1 && bomba[hanyadik].y == tipp.y)
                return true;}
        if (palya.y>tipp.y+1 && 0<tipp.y+1){
            if (bomba[hanyadik].x == tipp.x && bomba[hanyadik].y == tipp.y+1)
                return true;}
        if (palya.x>tipp.x-1 && 0<tipp.x-1 && palya.y>tipp.y-1 && 0<tipp.y-1){
            if (bomba[hanyadik].x == tipp.x-1 && bomba[hanyadik].y == tipp.y-1)
                return true;}
        if (palya.x>tipp.x+1 && 0<tipp.x+1 && palya.y>tipp.y+1 && 0<tipp.y+1){
            if (bomba[hanyadik].x == tipp.x+1 && bomba[hanyadik].y == tipp.y+1)
                return true;}
        if(palya.x>tipp.x-1 && 0<tipp.x-1 && palya.y>tipp.y+1 && 0<tipp.y+1){
            if (bomba[hanyadik].x == tipp.x-1 && bomba[hanyadik].y == tipp.y+1)
                return true;}
        if(palya.x>tipp.x+1 && 0<tipp.x+1 && palya.y>tipp.y-1 && 0<tipp.y-1){
            if (bomba[hanyadik].x == tipp.x+1 && bomba[hanyadik].y == tipp.y-1)
                return true;}
    }
    return false;
}

int szamostomb_bombaszamlalo (Koord *bomba,Koord tipp, Koord palya, int bombadb)
{
    int szamlalo=0;
    for (int i=0; i<bombadb;i++)
    {
        if (tipp.x == bomba[i].x && tipp.y == bomba[i].y){
            return 9;
        }else {
                if (tipp.x == bomba[i].x && tipp.y-1 == bomba[i].y){ //balra
                szamlalo++;}
                if (tipp.x-1 == bomba[i].x && tipp.y-1 == bomba[i].y){ //bal fent
                szamlalo++;}
                if (tipp.x+1 == bomba[i].x && tipp.y-1 == bomba[i].y){ //bal lent
                szamlalo++;}
                if (tipp.x == bomba[i].x && tipp.y+1 == bomba[i].y){ //jobb
                szamlalo++;}
                if (tipp.x-1 == bomba[i].x && tipp.y+1 == bomba[i].y){ //jobb fent
                szamlalo++;}
                if (tipp.x+1 == bomba[i].x && tipp.y+1 == bomba[i].y){ //jobb lent
                szamlalo++;}
                if (tipp.x-1 == bomba[i].x && tipp.y == bomba[i].y){ // fent
                szamlalo++;}
                if (tipp.x+1 == bomba[i].x && tipp.y == bomba[i].y){ //lent
                szamlalo++;}
        }
    }
    return szamlalo;
}

void szamostomb_gen (int **szamostomb,Koord *bomba,Koord palya, int bombadb)
{
    Koord aktualis;
    int szam;
    for (int i=0;i<palya.y;i++){
        for(int j=0;j<palya.x;j++){
            aktualis.x=j;
            aktualis.y=i;
            szam=szamostomb_bombaszamlalo(bomba,aktualis,palya,bombadb);
            szamostomb[i][j] = szam;
        }
    }
}

bool tipp_palyan (Koord palya, Koord tipp)
{
    if (tipp.x>palya.x || tipp.x<0 || tipp.y>palya.y || tipp.y<0)
    {
        printf("A tipped nincs rajta a palyan. Kerlek probalkozz ujra:\n(SOR OSZLOP):");
        return false;
    }
    else
    return true;
}

bool fvo_helyes (char fvo)
{
    if (fvo == 'f' || fvo == 'o' || fvo == 'F' || fvo == 'O')
        return true;
    else
        printf("Ezt az utasitast nem lehet vegrehajtani!");
        return false;
}
