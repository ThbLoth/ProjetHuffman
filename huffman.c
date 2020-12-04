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

    int i,j,nb_carac_total = 0,compteur=0;
    int tab[128] = {0};
    int carac;
    list minimum =malloc(sizeof(node));
    list stock_occ=malloc(sizeof(node));
    list premier_maillon = stock_occ;


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

    for(i=0;i<128;i++)
    {
        if(tab[i]!= 0)
            nb_carac_total +=1;
    }

    do{
         for(i=0;i<128;i++)
         {
             if(tab[i] !=0)
             {
                 minimum->lettre =i;
                 minimum->nb_occ =tab[i];
             }

             for(j=0;j<128;j++)
             {
                 if(tab[j]!=0)
                 {
                     if(tab[j]<minimum->nb_occ)
                     {
                         minimum->lettre = j;
                         minimum->nb_occ = tab[j];
                     }
                 }
             }
         }

        premier_maillon->lettre = minimum->lettre;
        premier_maillon->nb_occ = minimum->nb_occ;
        printf("Lettre='%c',Occurences=%d\n",premier_maillon->lettre,premier_maillon->nb_occ);
        premier_maillon->succ=malloc(sizeof(node));
        premier_maillon=premier_maillon->succ;

        tab[minimum->lettre] =0;

        compteur +=1;
    }while(compteur !=nb_carac_total);



    return stock_occ;
}

