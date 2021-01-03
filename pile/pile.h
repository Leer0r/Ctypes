typedef struct pile pile;

struct pile
{
    int size;
    int *tab;
    int libre;
};

pile *nouvelle_pile(int length);

int est_vide(pile *p);

int empiler(pile *p, int value);

void afficher_pile(pile *p);

int depiler(pile *p);

void detruire_pile(pile *p);
