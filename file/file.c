#include "file.h"
#include <stdio.h>
#include <stdlib.h>

file file_vide(void)
{
    file f = malloc(sizeof(file));
    f->queue = NULL;
    f->tete = NULL;
    return f;
}

int est_vide(file f)
{
    return f->tete == NULL;
}

void enfiler(int value, file f)
{
    elem new_elem = malloc(sizeof(elem));
    new_elem->value = value;
    new_elem->suivant = NULL;
    if (est_vide(f))
    {
        f->tete = new_elem;
        f->queue = new_elem;
    }
    else
    {
        f->queue->suivant = new_elem;
        f->queue = f->queue->suivant;
    }
}

elem tete(file f)
{
    return f->tete;
}

int defiler(file f)
{
    int defile_elem = f->tete->value;
    if (est_vide(f))
    {
        printf("file vide");
        return 0;
    }
    if (f->tete == f->queue)
    {
        f->queue = NULL;
        free(f->tete);
        f->tete = NULL;
    }
    else
    {
        elem current_tete = f->tete;
        f->tete = f->tete->suivant;
        free(current_tete);
    }
    return defile_elem;
}

void detruire_file(file f)
{
    while (f->tete != NULL)
    {
        elem tmp = f->tete;
        f->tete = f->tete->suivant;
        free(tmp);
    }
    free(f);
}