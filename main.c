#include <stdio.h>
#include <stdlib.h>
#include "HUFFMAN.h"
#include "huffman.c"

int main()
{
    FILE * fic;

    list liste_occurence;

    fic = fopen("Alice.txt","r");

    Conversion(fic);
    CompteCarac();
    liste_occurence=nb_Occurrences();
    
    return 0;
}
