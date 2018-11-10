#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"


// Création fonction choix
void choix (int Num)
{
    // Création du fichier param.h
    FILE *fichier = NULL;
    fichier = fopen("coeur\\param.h", "w+");

            // Retourner la valeur saisie dans le fichier créé
            fprintf(fichier, "int parametre(){return %d;}", Num);

        // Fermer le fichier
        fclose(fichier);


}







