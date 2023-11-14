#ifndef GENERALAS_H_INCLUDED
#define GENERALAS_H_INCLUDED

bool marletezik (Koord *bomba, int hanyadik);
void szamostomb_gen (int **szamostomb,Koord *bomba,Koord palya, int bombadb);
int szamostomb_bombaszamlalo (Koord *bomba,Koord tipp, Koord palya, int bombadb);
bool tipp_palyan (Koord palya, Koord tipp);
bool fvo_helyes (char fvo);
bool elsotipp (Koord *bomba, int hanyadik, Koord tipp, Koord palya);


#endif // GENERALAS_H_INCLUDED
