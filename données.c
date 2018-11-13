#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

void readDonnees(File *file){
    struct mesure Mesure;
    int rangLigne = -1, caractereActuel = 0,  stop = 0;
    FILE *fichier = NULL;
    char motFichier[100];

    fichier = fopen("Battements.csv","r");

    if(fichier != NULL){
        while(1){
            while(caractereActuel != ';'){
                caractereActuel = getc(fichier);
                if(caractereActuel == -1){
                    stop = 1;
                    break;
                }
                rangLigne++;
                motFichier[rangLigne] = caractereActuel;
            }
            if(stop == 1){
                break;
            }

            Mesure.pouls = atoi(motFichier);
            rangLigne = -1;

            while(caractereActuel != '\n'){
                caractereActuel = getc(fichier);
                rangLigne++;
                motFichier[rangLigne] = caractereActuel;
            }

            Mesure.temps = atoi(motFichier);
            rangLigne = -1;

            enfilage(file, Mesure);

        }

    }else{
        printf("Erreur lors de l'ouverture du fichier : Fichier introuvable !");
    }
}

File *initialisation()
{
    File *file = malloc(sizeof(*file));
    Element *element = malloc(sizeof(*element));

    if (file == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->Mesure.pouls = 0;
    element->Mesure.temps = 0;
    element->suivant = NULL;
    file->premier = element;

    return file;
}

void enfilage(File *file, mesure mesure){
    Element *newElement = malloc(sizeof(*newElement));
    if (file == NULL || newElement == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newElement->Mesure = mesure;
    newElement->suivant = NULL;

    if (file->premier != NULL)
    {
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = newElement;
    }
    else
    {
        file->premier = newElement;
    }
}


