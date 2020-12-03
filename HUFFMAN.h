#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED

typedef struct node {
	int lettre;
  int nb_occ;
	struct node *succ;
} node;

typedef node * list;

void Conversion(FILE*);
void CompteCarac(void);
list nb_Occurrences(void);

#endif // HUFFMAN_H_INCLUDED
