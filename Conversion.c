#include <stdio.h>
#include "Conversion.h"

void Conversion(FILE* fic)
{
    FILE* fout;
    int carac;
    int bin = 128;
    fopen_s(&fout,"binary.txt", "w");

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

    while ((carac = fgetc(fic)) != EOF)
    {
        while (carac > -1)
        {
            fprintf(fout, "%d", carac / bin);

            if (carac >= bin)
            {
                carac = carac - bin;
            }

            bin = bin / 2;

            if (bin == 0)
            {
                break;
            }
        }

        bin = 128;
    }

    fclose(fout);
    fclose(fic);
}