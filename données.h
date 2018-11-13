typedef struct mesure mesure;
struct mesure{
    int temps;
    int pouls;
};

typedef struct Element Element;
struct Element{
    struct mesure Mesure;
    struct Element *suivant;
};

typedef struct File File;
struct File
{
    Element *premier;
};

void readDonnees();
File *initialisation();
void insertion(File *File, mesure mesure);
