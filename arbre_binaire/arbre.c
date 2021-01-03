#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>

int estVide(arbre a)
{
    return a == NULL;
}

node new_node(node FG, int value, node FD)
{
    node n_node = malloc(sizeof(node));
    n_node->value = value;
    n_node->FG = FG;
    n_node->FD = FD;
    n_node->pere = NULL;
    return n_node;
}

node tete(arbre a)
{
    return a;
}

node FG(node n)
{
    return n->FG;
}

node FD(node n)
{
    return n->FD;
}

int key(node n)
{
    return n->value;
}

void print_node(node n)
{
    if (n == NULL)
    {
        printf("Vide <-- Vide --> Vide\n");
        return;
    }
    if (FG(n) == NULL)
    {
        printf("Vide <-- ");
    }
    else
    {
        printf("%d <-- ", FG(n)->value);
    }
    printf("%d", n->value);
    if (FD(n) == NULL)
    {
        printf(" --> Vide");
    }
    else
    {
        printf(" --> %d", FD(n)->value);
    }
    printf("\n");
}

//Partie pour les arbres binaire de recherche

void inserer_ABR(node elem, ABR abr)
{
    if (key(abr) == key(elem))
    {
        return;
    }
    if (key(abr) > key(elem))
    {
        if (FG(abr) == NULL)
        {
            elem->pere = abr;
            abr->FG = elem;
        }
        else
        {
            inserer_ABR(elem, FG(abr));
        }
    }
    else
    {
        if (FD(abr) == NULL)
        {
            elem->pere = abr;
            abr->FD = elem;
        }
        else
        {
            inserer_ABR(elem, FD(abr));
        }
    }
}

int as_value(int value, ABR abr)
{
    if (est_vide(abr))
    {
        return 0;
    }
    if (key(abr) == value)
    {
        return 1;
    }
    if (key(abr) > value)
    {
        return as_value(value, FD(abr));
    }
    else
    {
        return as_value(value, FG(abr));
    }
}

int min(ABR abr)
{
    if (est_vide(FG(abr)))
    {
        return key(abr);
    }
    return min(FG(abr));
}

void main(void)
{
    ABR a = new_node(NULL, 3, NULL);
    inserer_ABR(new_node(NULL, 2, NULL), a);
    inserer_ABR(new_node(NULL, 4, NULL), a);
    inserer_ABR(new_node(NULL, 5, NULL), a);
    print_node(FD(a));
}