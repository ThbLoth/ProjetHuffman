#include <stdio.h>
#include "NombreOccurrence.h"
#include "Structures.h"

node* creation_liste_occ(int lettre, int nb_occ)
{
    node* nouvel_element = (node*)malloc(sizeof(node));
    nouvel_element->lettre = lettre;
    nouvel_element->nb_occ = nb_occ;
    nouvel_element->succ = NULL;
    return nouvel_element;
}

void nb_Occurrences(list* stock_occ)
{
    int i;
    int tab[128] = { 0 };
    int carac;
    list temp;
    FILE* fic;

    fopen_s(&fic,"Alice.txt", "r");

    if (fic == NULL)
    {
        perror("Fichier d'origine illisible");
        exit(-1);
    }

    while ((carac = fgetc(fic)) != EOF)
    {
        tab[carac]++;
    }

    for (i = 0; i < 128; i++)
    {
        if (tab[i] != 0)
        {
            if (*stock_occ == NULL)
            {
                *stock_occ = creation_liste_occ(i, tab[i]);
                temp = *stock_occ;
            }
            else
            {
                temp->succ = creation_liste_occ(i, tab[i]);
                temp = temp->succ;
            }
        }
    }
}