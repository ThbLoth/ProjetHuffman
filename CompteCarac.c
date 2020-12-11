#include <stdlib.h>
#include <stdio.h>
#include "CompteCarac.h"

void CompteCarac(void)
{
    FILE* fic;
    FILE* fout;

    fopen_s(&fic, "Alice.txt", "r");;
    fopen_s(&fout,"output.txt", "w");

    int compteur = 0;

    if (fic == NULL)
    {
        perror("Fichier d'origine illisible");
        exit(-1);
    }

    if (fout == NULL)
    {
        perror("Fichier de sortie illisible");
        exit(-1);
    }

    while (getc(fic) != EOF)
    {
        compteur = compteur + 1;
    }
    fprintf(fout, "Le fichier d'entree contient %d caracteres", compteur);

    fclose(fout);
    fclose(fic);
}