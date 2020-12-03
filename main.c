#include <stdio.h>
#include <stdlib.h>
#include "HUFFMAN.h"
#include "huffman.c"

int main()
{
    FILE * fic;
    fic = fopen("Alice.txt","r");

    Conversion(fic);
    return 0;
}
