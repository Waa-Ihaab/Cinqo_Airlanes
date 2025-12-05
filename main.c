#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vol.h"

int main(int argc, char *argv[]) {

    FILE *f = fopen("data.csv", "r");
    if (!f) {
        perror("Erreur data");
        return 1;
    }

    int nbVols = 0;
    Vol *vols = volValid(f, &nbVols);

    fclose(f);

    if (!vols) {
        printf("Erreur chargement des vols.\n");
        return 1;
    }

    // SI AUCUN ARGUMENT → afficher erreur
    if (argc < 2) {
        printf("Usage : app.exe LIST\n");
        printf("Usage : app.exe DIRECT Paris Nador\n");
        printf("Usage : app.exe CORRESP Paris Nador\n");
        free(vols);
        return 0;
    }

    // LIST
    if (strcmp(argv[1], "LIST") == 0) {
        afficherVols(vols, nbVols);
    }

    // DIRECT
    else if (strcmp(argv[1], "DIRECT") == 0 && argc == 4) {
        volDirect(vols, nbVols, argv[2], argv[3]);
    }

    // CORRESP
    else if (strcmp(argv[1], "CORRESP") == 0 && argc == 4) {
        volCorrespondances(vols, nbVols, argv[2], argv[3]);
    }


    //ecrire dans le fichier
    else if (strcmp(argv[1], "WRITE_DIRECT") == 0 && argc == 4) {
        const char *filename = "volhistorique.txt";
        
        for (int i = 0; i < nbVols; i++) {
            if (strcmp(vols[i].ville_depart, argv[2]) == 0 &&
                strcmp(vols[i].ville_arrivee, argv[3]) == 0) {

                writeInfile(vols[i], filename);
                printf("Vol direct ajouté.\n");
                break;  // Sortir après le premier vol trouvé
            }
        }
        
        free(vols);  // Libérer la mémoire
        return 0;
    }

        
    else if (strcmp(argv[1], "WRITE_CORRESP") == 0) {

        char *depart = argv[2];
        char *arrivee = argv[3];
        const char *filename = "volhistorique.txt";

        for (int i = 0; i < nbVols; i++) {
            for (int j = 0; j < nbVols; j++) {

                if (strcmp(vols[i].ville_depart, depart) == 0 &&
                    strcmp(vols[i].ville_arrivee, vols[j].ville_depart) == 0 &&
                    strcmp(vols[j].ville_arrivee, arrivee) == 0) {

                    writeInfile(vols[i], filename);
                    writeInfile(vols[j], filename);

                    printf("Correspondance enregistrée dans %s.\n", filename);
                    free(vols);  // ⚠️ AJOUTER ICI
                    return 0;
                }
            }
        }

        printf("Aucune correspondance trouvée.\n");
        free(vols);
        return 0;
    }

    else {
        printf("Commande inconnue ou arguments manquants.\n");
    }

    

    free(vols);
    return 0;
}
