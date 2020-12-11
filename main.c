#include <stdio.h>
#include <stdlib.h>
#include "CompressionHuffman.h"
#include "CompressionHuffman.c"

int main()
{
	remove("output.txt");
	remove("dico.txt");
	remove("traduction.txt");
	remove("binary.txt");

	encodage_huffman();
	return 0;
}

