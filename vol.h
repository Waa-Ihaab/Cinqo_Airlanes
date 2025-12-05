#ifndef VOL_H
#define VOL_H

#include <stdio.h>

#define taille_ligne 256

typedef struct {
    char id[10];
    char pays_depart[30];
    char ville_depart[30];
    char pays_arrivee[30];
    char ville_arrivee[30];
    char heure_depart[10];
    char heure_arrivee[10];
} Vol;

int estVolValide(Vol v);
Vol* volValid(FILE *f, int *nbVols);
void afficherVols(Vol *vols, int nbVols);

int heureVersMinutes(const char *heure);

void volDirect(Vol *vols, int nbVols, char *depart, char *arrivee);
void volCorrespondances(Vol *vols, int nbVols, char *depart, char *arrivee);



void writeInfile(Vol v, const char *filename);

#endif
