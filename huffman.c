#include <stdio.h>
#include <stdlib.h>

void Conversion(FILE * fic)
{
    FILE * fout;

    int carac;
    int bin = 128;

	fout = fopen("binary.txt","w");

	if (fic == NULL)
	{
	    perror("Fichier d'origine illisible");
		exit(-1);
	}

	if (fout  == NULL)
	{
	    perror("Fichier de sortie illisible");
		exit(-1);
	}

    while ((carac = fgetc(fic)) != EOF)
    {
        while(carac > -1)
        {
            fprintf(fout,"%d",carac/bin);

            if(carac>=bin)
            {
                carac = carac - bin;
            }

            bin = bin/2;

            if (bin == 0)
                break;
        }
        bin = 128;

    }

    fclose(fout);
    fclose(fic);
}

void CompteCarac(void)
{
    FILE * fic;
    FILE * fout;

    fic = fopen("binary.txt","r");
    fout = fopen("output.txt","w");

    int compteur = 0;

	if (fic  == NULL)
	{
	    perror("Fichier d'origine illisible");
		exit(-1);
	}

	if (fout  == NULL)
	{
	    perror("Fichier de sortie illisible");
		exit(-1);
	}

    while(getc(fic)!= EOF)
    {
        compteur = compteur +1 ;
    }



    fprintf(fout,"Le fichier d'entree contient %d caracteres",compteur);

    fclose(fout);
    fclose(fic);
}
