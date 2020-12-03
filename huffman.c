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

    fic = fopen("Alice.txt","r");
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

list nb_Occurrences()
{

    int i;
    int tab[128] = {0};
    int carac;
    list stock_occ=malloc(sizeof(node));

    FILE * fic;

    fic = fopen("Alice.txt","r");

    if (fic == NULL)
	{
	    perror("Fichier d'origine illisible");
		exit(-1);
	}

    while ((carac = fgetc(fic)) != EOF)
    {
        tab[carac]++;
    }

    for(i=0;i<=127;i++)
    {
        if (tab[i]!=0)
        {
            stock_occ->lettre=i;
            stock_occ->nb_occ=tab[i];
            printf("Lettre = '%c', Occurences = %d\n",i,tab[i]);
            stock_occ->succ=malloc(sizeof(node));
            stock_occ= stock_occ->succ;
        }

      }

    return stock_occ;
}
