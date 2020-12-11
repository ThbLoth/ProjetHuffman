/*****************************************************************//**
 * \file   CreationArbreHuffman.c
 * \brief  Fichier source comprenant les fonctions permettant de creer un arbre d'Huffman.
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
#include "CreationArbreHuffman.h"
#include "Structures.h"


arbre creation_noeud(int lettre, int occ)
{
    arbre nouveau_noeud = (tree_node*)malloc(sizeof(arbre));
    nouveau_noeud->lettre = lettre;
    nouveau_noeud->nb_occ = occ;
    nouveau_noeud->right = NULL;
    nouveau_noeud->left = NULL;
    return nouveau_noeud;
}


tree_array* creation_elem_noeud(int lettre, int occ)
{
    tree_array* nouvel_element = (tree_array*)malloc(sizeof(tree_array));
    nouvel_element->data = creation_noeud(lettre, occ);
    nouvel_element->next = NULL;
    return nouvel_element;
}


tree_array* creation_liste_arbre(node* liste_occ)
{
    if (liste_occ != NULL)
    {
        tree_array* ListeArbre = creation_elem_noeud(liste_occ->lettre, liste_occ->nb_occ);
        tree_array* temp = ListeArbre;
        liste_occ = liste_occ->succ;

        while (liste_occ != NULL)
        {
            temp->next = creation_elem_noeud(liste_occ->lettre, liste_occ->nb_occ);
            liste_occ = liste_occ->succ;
            temp = temp->next;
        }

        return ListeArbre;
    }
    return NULL;
}


arbre arbre_huffman(tree_array* liste)
{
    if (liste == NULL)
    {
        return NULL;
    }

    tree_array* temp = NULL;
    tree_array* temp2 = NULL;
    tree_array* min1 = NULL;
    tree_array* min2 = NULL;

    while (liste->next != NULL)
    {
        temp = liste;
        min1 = liste;
        temp2 = NULL;
        while (temp->next != NULL)
        {
            if (min1->data->nb_occ > temp->next->data->nb_occ)
            {
                temp2 = temp;
                min1 = temp->next;
            }

            temp = temp->next;
        }

        if (temp2 == NULL)
        {
            liste = liste->next;
        }
        else
        {
            temp2->next = temp2->next->next;
        }
        temp = liste;
        min2 = liste;
        temp2 = NULL;

        if (min1 == liste)
        {
            min2 = liste->next;
            temp = liste->next;
        }

        while (temp->next != NULL)
        {
            if ((min2->data->nb_occ > temp->next->data->nb_occ) && temp->next != min1)
            {
                temp2 = temp;
                min2 = temp->next;
            }
            temp = temp->next;
        }

        if (temp2 == NULL)
        {
            liste = liste->next;
        }

        else
        {
            temp2->next = temp2->next->next;
        }

        temp = creation_elem_noeud(36, min1->data->nb_occ + min2->data->nb_occ);
        temp->data->right = min1->data;
        temp->data->left = min2->data;
        temp->next = liste;
        liste = temp;
    }

    return liste->data;
}