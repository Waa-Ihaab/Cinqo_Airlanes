#include "vol.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int estVolValide(Vol v) {
    if (strlen(v.ville_depart) == 0 || strlen(v.ville_arrivee) == 0 || strlen(v.pays_depart) == 0 || strlen(v.pays_arrivee) == 0)
        return 0;

    if (strstr(v.pays_depart, "?") || strstr(v.ville_depart, "?"))
        return 0;

    if (strcmp(v.ville_depart, v.ville_arrivee) == 0)
        return 0;

    return 1;
}

Vol* volValid(FILE *f, int *nbVols) {

    char ligne[taille_ligne];
    int capacite = 10, compteur = 0;

    Vol *tableau = malloc(capacite * sizeof(Vol));
    if (!tableau) return NULL;

    fgets(ligne, taille_ligne, f);

    while (fgets(ligne, taille_ligne, f)) {

        Vol v;

        if (ligne[0] == '\n' || ligne[0] == '-')
            continue;

        int champs = sscanf(ligne, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]", v.id, v.pays_depart, v.ville_depart, v.pays_arrivee, v.ville_arrivee, v.heure_depart, v.heure_arrivee);

        if (champs != 7 || !estVolValide(v))
            continue;

        if (compteur >= capacite) {
            capacite *= 2;
            Vol *tmp = realloc(tableau, capacite * sizeof(Vol));
            if (!tmp) return NULL;
            tableau = tmp;
        }

        tableau[compteur++] = v;
    }

    *nbVols = compteur;
    return tableau;
}

void afficherVols(Vol *vols, int nbVols) {

    if (nbVols == 0) {
        printf("Aucun vol valide.\n");
        return;
    }

    for (int i = 0; i < nbVols; i++) {
        printf("%s : %s (%s) -> %s (%s) | %s - %s\n", vols[i].id, vols[i].ville_depart, vols[i].pays_depart, vols[i].ville_arrivee, vols[i].pays_arrivee, vols[i].heure_depart, vols[i].heure_arrivee);
    }
}



int heureVersMinutes(const char *heure) {
    int h, m;
    if (sscanf(heure, "%d:%d", &h, &m) != 2)
        return -1;

    return h * 60 + m;
}




void volDirect(Vol *vols, int nbVols, char *depart, char *arrivee) {

    printf("\nRecherche de vols directs : %s -> %s\n", depart, arrivee);

    int trouve = 0;

    for (int i = 0; i < nbVols; i++) {
        if (strcmp(vols[i].ville_depart, depart) == 0 &&
            strcmp(vols[i].ville_arrivee, arrivee) == 0) {

            printf("\nVol direct trouve :\n");
            printf("%s : %s -> %s | %s - %s\n", vols[i].id, vols[i].ville_depart, vols[i].ville_arrivee, vols[i].heure_depart, vols[i].heure_arrivee);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun vol direct trouve.\n");
    }
}

void volCorrespondances(Vol *vols, int nbVols, char *depart, char *arrivee) {

    printf("\nRecherche de vols avec correspondances : %s -> %s\n", depart, arrivee);

    int trouve = 0;

    // Vols directs
    for (int i = 0; i < nbVols; i++) {
        if (strcmp(vols[i].ville_depart, depart) == 0 &&
            strcmp(vols[i].ville_arrivee, arrivee) == 0) {

            printf("\nVol direct trouve :\n");
            printf("%s : %s -> %s | %s - %s\n", vols[i].id, vols[i].ville_depart, vols[i].ville_arrivee, vols[i].heure_depart, vols[i].heure_arrivee);
            trouve = 1;
        }
    }

    //Vols avec une seule correspondance
    for (int i = 0; i < nbVols; i++) {

        // Premier vol : départ -> escale
        if (strcmp(vols[i].ville_depart, depart) == 0) {

            for (int j = 0; j < nbVols; j++) {

                // Deuxième vol : escale -> arrivée
                if (strcmp(vols[i].ville_arrivee, vols[j].ville_depart) == 0 &&
                    strcmp(vols[j].ville_arrivee, arrivee) == 0) {

                    int arrivee1 = heureVersMinutes(vols[i].heure_arrivee);
                    int depart2 = heureVersMinutes(vols[j].heure_depart);

                    // Vérifier que le deuxième vol est après le premier
                    if (arrivee1 < depart2) {

                        printf("\nVol avec correspondance :\n");
                        printf("1) %s : %s -> %s | %s - %s\n", vols[i].id, vols[i].ville_depart, vols[i].ville_arrivee, vols[i].heure_depart, vols[i].heure_arrivee);
                        printf("2) %s : %s -> %s | %s - %s\n", vols[j].id, vols[j].ville_depart, vols[j].ville_arrivee, vols[j].heure_depart, vols[j].heure_arrivee);
                        trouve = 1;
                    }
                }
            }
        }
    }

        if (!trouve) {
            printf("Aucune correspondance trouvee.\n");
        }
    }
    
    void billet(Vol v, const char *filename) {
    FILE *f = fopen(filename, "w");

    if (!f) {
        printf("Erreur creation fichier billet.\n");
        return;
    }

    fprintf(f, "      *** Cinqo Airlines ***      \n");

    fprintf(f, "Vol : %s\n", v.id);
    fprintf(f, "Trajet : %s (%s) -> %s (%s)\n",
            v.ville_depart, v.pays_depart,
            v.ville_arrivee, v.pays_arrivee);

    fprintf(f, "Heure depart  : %s\n", v.heure_depart);
    fprintf(f, "Heure arrivee : %s\n", v.heure_arrivee);

    fprintf(f, "\n      *** Cinqo Airlines ***      \n");
    fprintf(f, "MERCI POUR VOTRE CONFIANCE\n");

    fclose(f);

    printf("Billet genere : %s\n", filename);
}


// i want to create a function that writes the flight information in a pdf file 
// if the file already exists we write at the end of the file if not we create it
void writeInfile(Vol v, const char *filename) {
    FILE *f = fopen(filename, "a");
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    if (!f) {
        printf("Erreur creation fichier pdf.\n");
        return;
    }
    fprintf(f, "-----------------------------------\n");
    fprintf(f, "Vol : %s\n", v.id);
    fprintf(f, "Trajet : %s (%s) -> %s (%s)\n",
            v.ville_depart, v.pays_depart,
            v.ville_arrivee, v.pays_arrivee);
    fprintf(f, "Heure depart  : %s\n", v.heure_depart);
    fprintf(f, "Heure arrivee : %s\n", v.heure_arrivee);

    fprintf(f, "Pris le : %04d-%02d-%02d à %02d:%02d:%02d\n",
            tm->tm_year + 1900,
            tm->tm_mon + 1,
            tm->tm_mday,
            tm->tm_hour,
            tm->tm_min,
            tm->tm_sec);

    fprintf(f, "-----------------------------------\n\n");
    fclose(f);
}


