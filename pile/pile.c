#include "pile.h"
#include <stdio.h>
#include <stdlib.h>

pile *nouvelle_pile(int length)
{
    pile *p = malloc(sizeof(pile));
    if (p == NULL)
    {
        return NULL;
    }
    p->size = length;
    p->libre = 0;
    p->tab = malloc(sizeof(int) * length);
}

int est_vide(pile *p)
{
    return p->libre == 0;
}

int empiler(pile *p, int value)
{
    if (p->libre == p->size)
    {
        int *new_tab = malloc(sizeof(int) * (p->size * 2));
        for (int i = 0; i < p->size - 1; i++)
        {
            new_tab[i] = p->tab[i];
        }
        free(p->tab);
        p->tab = new_tab;
        p->size *= 2;
    }
    p->tab[p->libre] = value;
    p->libre++;
    return 0;
}

void afficher_pile(pile *p)
{
    if (!est_vide(p))
    {
        for (int i = 0; i < p->libre; i++)
        {
            printf("%d ", p->tab[i]);
        }
        printf("\n");
    }
    else
    {
        printf("pile vide\n");
    }
}

int depiler(pile *p)
{
    if (!est_vide(p))
    {
        int value = p->tab[p->libre - 1];
        p->libre--;
        return value;
    }
    exit(0);
}

void detruire_pile(pile *p)
{
    free(p->tab);
    free(p);
}