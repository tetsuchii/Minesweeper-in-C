#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include "nullazas.h"
#include "palya.h"
#include "generalas.h"


int main()
{
    srand(time(0));
    Koord palya;
    int bombadb;
    Koord tipp;
    bool palyanvan;
    char fvo;
    bool fvoh;

//Szövegelõs rész

    printf("A jatek kezdesehez add meg, mekkora palyan szeretnel jatszani:\n");
    printf("Szelesseg:\n");
    scanf("%d", &palya.x);
    if (palya.x <2)
    {
        printf("A palya szelessege nem lehet kisebb kettonel. Kerlek adj meg uj szelesseget!\nSzelesseg:");
        scanf("%d", &palya.x);
    }
    printf("Magassag:\n");
    scanf("%d", &palya.y);
    if (palya.y <2)
    {
        printf("A palya magassaga nem lehet kisebb kettonel. Kerlek adj meg uj magassagot!\nMagassag:");
        scanf("%d", &palya.y);
    }
    printf("Hany bombat szeretnel a palyara?\n");
    scanf("%d", &bombadb);
    if (bombadb<1 || bombadb>palya.x*palya.y)
    {
        printf("Hibas adat. Valassz 1 es %d kozott. Kerlek adj meg egy uj szamot!\nBombak szama:", palya.x*palya.y);
        scanf("%d", &bombadb);
    }
    // ELSŐ TIPP: Mivel az első tippnek mindenképp 0-nak kell lennie, így a bombagenerálás előtt kell lennie. Az előtte megjelenő pálya úgymond csak "dísz", nem valós 2D-s tömb.
    system("cls");
    printf("Aknakereso\nSzelesseg: %d Magassag: %d Bombak szama: %d\n", palya.x,palya.y,bombadb);
    printf("A jatek soran koordinatak megadasaval tudsz jatszani.\nEldontheted, hogy egy mezot megjelolsz(F) vagy felnyitsz(O). Ezt ilyen formaban tedd: SZAM SZAM F/O\n");
    disztomb(palya);
    //Az első tipp bekérése során két bool fgv ellenőrzi,hogy a tipp helyes volt-e (azaz rajta van-e a pályán és helyesen lett-e megadva.
    do {
            printf("\n Melyik mezot? (SOR OSZLOP F/O)");
            scanf("%d %d %c", &tipp.y, &tipp.x, &fvo);
            palyanvan=tipp_palyan(palya,tipp);
            fvoh=fvo_helyes(fvo);
        }while (palyanvan != true || fvoh !=true);
    // BOMBÁK generálása: Random koordináták kiválasztása a pályáról, sima Koord-ként, majd ellenőrzés, hogy volt-e már ilyen, illetve nem-e ez volt az első tipp, ha az előbbi vagy az utóbbi fenn áll, újból generál
    Koord *bomba = (Koord*) malloc(bombadb*sizeof(Koord));
    for (int i=0; i < bombadb; i++)
    {
        bomba[i].x = rand()%palya.x ;
        bomba[i].y = rand()%palya.y ;
        while (elsotipp(bomba,i,tipp,palya) || marletezik(bomba,i)){
            bomba[i].x = rand()%palya.x ;
            bomba[i].y = rand()%palya.y ;
        }
    }
    //Pálya lefoglalása:
    int **szamostomb;
        szamostomb = (int**) malloc(palya.y*sizeof(int*));
        szamostomb[0] = (int*) malloc(palya.x*palya.y*sizeof(int));
        for (int i=0;i<palya.y;i++)
            szamostomb[i] = szamostomb[0] + i*palya.y;
    //Palya foglalás 2
    int **mezok;
    mezok = (int**) malloc(palya.y*sizeof(int*));
    mezok[0] = (int*) malloc(palya.y * palya.x *sizeof(int));
    for (int i=1;i<palya.y;i++)
        mezok[i] = mezok[0] + i*palya.y;
    //Pálya feltöltése: Megnézi, hogy hol mennyi bombát talál és azt az értéket adja meg a 2D-s tömb egyes mezőinek. Mivel 9 nem lehet egy mezőn sem, így ezek jelzik a bombát.
    szamostomb_gen(szamostomb,bomba,palya,bombadb);
    palya_feltolt(mezok,palya);
    //ELSŐ TIPP érvényesítése:
    mezok[tipp.y][tipp.x]=szamostomb[tipp.y][tipp.x];
    nullazas(tipp.x,tipp.y,mezok,szamostomb,palya);
    bool jatek=true;
    while (jatek)
    {
        system("cls");
        printf("Aknakereso\nSzelesseg: %d Magassag: %d Bombak szama: %d\n", palya.x,palya.y,bombadb);
        printf("A jatek soran koordinatak megadasaval tudsz jatszani.\nEldontheted, hogy egy mezot megjelolsz(F) vagy felnyitsz(O). Ezt ilyen formaban tedd: SZAM SZAM F/O\n");
        for (int i=0; i < bombadb; i++)
            printf("%d %d | ", bomba[i].y, bomba[i].x);
        printf("\n");
        palya_kiir(tipp,szamostomb, palya, mezok);
        printf("\n");
        //Tipp bekérése és ellenőrzése
        do {
            printf("\n Melyik mezot? (SOR OSZLOP F/O)");
            scanf("%d %d %c", &tipp.y, &tipp.x, &fvo);
            palyanvan=tipp_palyan(palya,tipp);
            fvoh=fvo_helyes(fvo);
        }while (palyanvan != true || fvoh !=true);
        if (fvo == 'f')
        {
                mezok[tipp.y][tipp.x]=12;
        }else{
        int szamlalo=szamostomb_bombaszamlalo(bomba,tipp,palya,bombadb);
        felfedes(tipp,szamlalo, mezok, szamostomb, jatek);
        }
    }

    free(mezok[0]);
    free(mezok);
    free(szamostomb[0]);
    free(szamostomb);
    free(bomba);
    return 0;
}
