#include <stdio.h>
#include <stdlib.h>
#include "CompressionHuffman.h"
#include "Structures.h"
#include "Conversion.h"
#include "Conversion.c"
#include "CompteCarac.h"
#include "CompteCarac.c"
#include "NombreOccurrence.h"
#include "NombreOccurrence.c"
#include "CreationArbreHuffman.h"
#include "CreationArbreHuffman.c"
#include "CreationDictionnaireHuffman.h"
#include "CreationDictionnaireHuffman.c"
#include "EncodageTexte.h"
#include "EncodageTexte.c"


void encodage_huffman(void)
{
    FILE* fic;
    list liste_occurence = NULL;
    arbre arbre_huff;
    tree_array* liste_transformee = NULL;
    list_binaire* binaire = NULL;
    fopen_s(&fic,"Alice.txt", "r");
    Conversion(fic);
    CompteCarac();
    nb_Occurrences(&liste_occurence);
    liste_transformee = creation_liste_arbre(liste_occurence);
    arbre_huff = arbre_huffman(liste_transformee);
    Creation_Dico(arbre_huff, binaire);
    encodage();
}