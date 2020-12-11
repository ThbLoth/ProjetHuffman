#include <stdio.h>
#include <stdlib.h>
#include "EncodageTexte.h"

void encodage(void)
{
    FILE* fic; 
    fopen_s(&fic,"Alice.txt", "r");

    FILE* fdic;  
    fopen_s(&fdic,"dico.txt","r");

    FILE* fout; 
    fopen_s(&fout,"traduction.txt","a");

    char lettre;
    if (fic == NULL || fdic == NULL || fout == NULL)
    {
        printf("Erreur mémoire");
        exit(1);
    }

    while ((lettre = fgetc(fic)) != EOF)
    {
        fseek(fdic, 0, SEEK_SET);
        while (fgetc(fdic) != lettre)
        {
            while (fgetc(fdic) != '\n')
            {
                lettre = lettre;
            }
        }

        fgetc(fdic);

        while ((lettre = fgetc(fdic)) != '\n')
        {
            fprintf(fout, "%c", lettre);
        }
    }
    fclose(fout);
    fclose(fdic);
    fclose(fic);
}