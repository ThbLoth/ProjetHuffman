/*****************************************************************//**
 * \file   CreationDictionnaireHuffman.c
 * \brief  Fichier source comprenant les fonctions permettant de creer le dictionnaire d'Huffman.
 * 
 * \author Maxime GARNIER maxime.garnier@efrei.net\n
 * Thibault LOTH thibault.loth@efrei.net\n
 * Theophile BAPTISTE BOUGON theophile.baptiste.bougon@efrei.net\n
 * Maladele WATT maladele.watt@efrei.net\n
 * Alexandre DELFOSSE alexandre.delfosse@efrei.net
 * \date   December 2020
 *********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "CreationDictionnaireHuffman.h"
#include "Structures.h"


list_binaire* Creation_list_binaire(int nb, list_binaire* binaire)
{
    list_binaire* nouveau = (list_binaire*)malloc(sizeof(list_binaire));
    nouveau->code = nb;
    nouveau->succ = NULL;
    if (binaire == NULL)
    {
        binaire = nouveau;
    }
    else
    {
        list_binaire* temp = binaire;

        while (temp->succ != NULL)
        {
            temp = temp->succ;
        }

        temp->succ = nouveau;
    }
    return binaire;
}

// fonction supprimant la derniere valeur d'une liste.

list_binaire* suppression_derniere_val(list_binaire* binaire)
{
    if (binaire == NULL)
    {
        return NULL;
    }

    if (binaire->succ == NULL)
    {
        return NULL;
    }

    list_binaire* temp = binaire;
    while (temp->succ->succ != NULL)
    {
        temp = temp->succ;
    }

    temp->succ = NULL;
    return binaire;
}

// création du dictionnaire de Huffman grace aux fonctions
// Creation_list_binaire, qui au fur et à mesure construit la suite binaires
// de chaque caractère, et suppression_derniere_val qui va supprimer le dernier chiffre
// car le dernier "chemin" correspond à la feuille.
void Creation_Dico(arbre a, list_binaire* binaire)
{
    if (a == NULL)
    {
        exit(-1);
    }

    FILE* fdic;

    if (a->left == NULL && a->right == NULL)
    {
        fopen_s(&fdic,"dico.txt", "a");

        if (fdic == NULL)
        {
            printf("Erreur mémoire");
            exit(-1);
        }

        fprintf(fdic, "%c:", a->lettre);

        while (binaire != NULL)
        {
            fprintf(fdic, "%d", binaire->code);
            binaire = binaire->succ;
        }

        fprintf(fdic, "\n");
        fclose(fdic);
    }

    else
    {
        Creation_Dico(a->left, Creation_list_binaire(0, binaire));
        binaire = suppression_derniere_val(binaire);
        Creation_Dico(a->right, Creation_list_binaire(1, binaire));
        binaire = suppression_derniere_val(binaire);
    }
}