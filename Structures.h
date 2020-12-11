
#ifndef STRUCTURES
#define STRUCTURES

typedef struct node
{
    int lettre;
    int nb_occ;
    struct node* succ;
} node;

typedef node* list;


typedef struct list_binaire
{
    int code;
    struct list_binaire* succ;
}list_binaire;


typedef struct tree_node
{
    int lettre;
    int nb_occ;
    struct tree_node* left, * right;
}tree_node;

typedef tree_node* arbre;


typedef struct tree_array
{
    struct tree_node* data;
    struct tree_array* next;
}tree_array;

#endif


