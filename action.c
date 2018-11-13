#include <stdio.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

void getAction(int action, File *file){
    int temps = 0, min = 0,max = 0;
    if(file != NULL){
        switch (action){
            case 1:
                printOrdre(file);
                break;
            case 2:
                printInverse(file);
                break;
            case 3:
                printCroissant(file);
                break;

            case 4:
                printDecroissant(file);
                break;

            case 5:
                printf("Pour quel instant voulez vous obtenir la valeur du pouls ?");
                scanf("%d",&temps);
                printPoulsTemps(file,temps);
                break;

            case 6:
                printf("Indiquez la plage de temps voulu !");
                scanf("%d %d",&min,&max);
                printMoyenne(file,min,max);
                break;

            case 7:
                printNbLigne(file);
                break;
            case 8:
                printMinMax(file);
                break;
            default:
                break;

        }
    }
}

void printOrdre(File *file){
    Element *actuel = file->premier;
    actuel = actuel->suivant;
    while(actuel != NULL){
        printf("Le pouls est de %d a l'instant %d\n",actuel->Mesure.pouls,actuel->Mesure.temps);
        actuel = actuel->suivant;
    }
}

void printInverse(File *file){
    int size = 0;
    Element *actuel = file->premier;
    actuel = actuel->suivant;
    while(actuel != NULL){
        size ++;
        actuel = actuel->suivant;
    }
    mesure tab[size];
    int i;
    actuel = file->premier;
    actuel = actuel->suivant;
    for(i = 0;i<size;i++){
        tab[i] = actuel->Mesure;
        actuel = actuel->suivant;
    }
    tri_bulle_decroissant_temps(size, tab);
    for(i = 0;i<size;i++){
        printf("Le pouls est de %d a l'instant %d\n",tab[i].pouls,tab[i].temps);
    }
}

void printCroissant(File *file){
    int size = 0;
    Element *actuel = file->premier;
    actuel = actuel->suivant;
    while(actuel != NULL){
        size ++;
        actuel = actuel->suivant;
    }
    mesure tab[size];
    int i;
    actuel = file->premier;
    actuel = actuel->suivant;
    for(i = 0;i<size;i++){
        tab[i] = actuel->Mesure;
        actuel = actuel->suivant;
    }
    tri_bulle_croissant_pouls(size, tab);
    for(i = 0;i<size;i++){
        printf("Le pouls est de %d a l'instant %d\n",tab[i].pouls,tab[i].temps);
    }
}

void printDecroissant(File *file){
    int size = 0;
    Element *actuel = file->premier;
    actuel = actuel->suivant;
    while(actuel != NULL){
        size ++;
        actuel = actuel->suivant;
    }
    mesure tab[size];
    int i;
    actuel = file->premier;
    actuel = actuel->suivant;
    for(i = 0;i<size;i++){
        tab[i] = actuel->Mesure;
        actuel = actuel->suivant;
    }
    tri_bulle_decroissant_pouls(size, tab);
    for(i = 0;i<size;i++){
        printf("Le pouls est de %d a l'instant %d\n",tab[i].pouls,tab[i].temps);
    }
}

void printPoulsTemps(File *file, int temps){
    int pouls = recherchePouls(temps, file);

    if(pouls != -1){
        printf("Le pouls est de %d a l'instant %d\n",pouls,temps);
    }
}

void printMoyenne(File *file, int min, int max){
    int size = 0, totalPouls = 0, poulsMoyen = 0, temp;
    Element *actuel = file->premier;
    actuel = actuel->suivant;
    Element *prec = file->premier;

    if(min > max){
        min = temp;
        min = max;
        max = temp;
    }

    while(actuel != NULL){
        if(actuel->Mesure.temps < max){
            prec = prec->suivant;
            actuel = actuel->suivant;
        }else{
            break;
        }
    }

    if(actuel == NULL){
        max = prec->Mesure.temps;
    }

    actuel = file->premier;
    actuel = actuel->suivant;

    if(min < actuel->Mesure.temps)min = actuel->Mesure.temps;

    actuel = file->premier;
    actuel = actuel->suivant;

    while(actuel->Mesure.temps < min && actuel != NULL){
        actuel = actuel->suivant;
    }
    if(actuel != NULL){
        while(actuel->Mesure.temps < max && actuel != NULL){
            totalPouls+=actuel->Mesure.pouls;
            size++;
            actuel = actuel->suivant;
        }
        if(actuel != NULL){
            totalPouls+=actuel->Mesure.pouls;
            size++;

            poulsMoyen = totalPouls/size;
            printf("Le pouls moyen est de %d\n", poulsMoyen);
        }
    }
}

void printNbLigne(File *file){
    int size = 0;
    Element *actuel = file->premier;
    actuel = actuel->suivant;
    while(actuel != NULL){
        size ++;
        actuel = actuel->suivant;
    }
    printf("Il y a %d valeur enregistre pour le moment !\n",size);
}

void printMinMax(File *file){
    int sizeMin = 1, sizeMax = 1,min = 500,max = 0, rngMin = 0, rngMax = 0,i;
    mesure minMesure[sizeMin], maxMesure[sizeMax];

    Element *actuel = file->premier;
    actuel = actuel->suivant;

    while(actuel != NULL){
        if(min > actuel->Mesure.pouls){
            sizeMin = 1;
            min = actuel->Mesure.pouls;
        }else if(min == actuel->Mesure.pouls){
            sizeMin++;
        }
        if(max < actuel->Mesure.pouls){
            sizeMax = 1;
            max = actuel->Mesure.pouls;
        }else if(max == actuel->Mesure.pouls){
            sizeMax++;
        }
        actuel = actuel->suivant;
    }

    actuel = file->premier;
    actuel = actuel->suivant;

    while(actuel != NULL){
        if(actuel->Mesure.pouls == min){
            minMesure[rngMin] = actuel->Mesure;
            rngMin++;
        }
        if(actuel->Mesure.pouls == max){
            maxMesure[rngMax] = actuel->Mesure;
            rngMax++;
        }
        actuel = actuel->suivant;
    }

    for(i = 0;i < sizeMin;i++){
        printf("Un pouls minimum est %d a l'instant %d\n",minMesure[i].pouls,minMesure[i].temps);
    }

    for(i = 0;i < sizeMax;i++){
        printf("Un pouls maximum est %d a l'instant %d\n",maxMesure[i].pouls,maxMesure[i].temps);
    }
}

int recherchePouls(int temps, File *file){
    Element *actuel = file->premier;
    actuel = actuel->suivant;
    Element *prec = file->premier;
    while(actuel->Mesure.temps <= temps && actuel != NULL){
        prec = prec->suivant;
        actuel = actuel->suivant;
    }
    if(actuel == NULL){
        return -1;
    }else{
        return prec->Mesure.pouls;
    }
}

void tri_bulle_croissant_pouls(int size, mesure tab[]){
    int change;
    mesure temp;
    do{
        int i;
        change = 0;
        for(i = 0;i<size-1;i++){
            if(tab[i].pouls > tab[i+1].pouls){
                temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                change = 1;
            }
        }
    }while(change == 1);
}

void tri_bulle_decroissant_pouls(int size, mesure tab[]){
    int change;
    mesure temp;
    do{
        int i;
        change = 0;
        for(i = 0;i<size-1;i++){
            if(tab[i].pouls < tab[i+1].pouls){
                temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                change = 1;
            }
        }
    }while(change == 1);
}

void tri_bulle_decroissant_temps(int size, mesure tab[]){
    int change;
    mesure temp;
    do{
        int i;
        change = 0;
        for(i = 0;i<size-1;i++){
            if(tab[i].temps < tab[i+1].temps){
                temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                change = 1;
            }
        }
    }while(change == 1);
}

