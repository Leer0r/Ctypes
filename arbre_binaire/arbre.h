typedef struct node *node;

struct node
{
    int value;
    node FG;
    node FD;
    node pere;
};

typedef struct node *arbre; //Arbre classique
typedef struct node *ABR;   //Arbre binaire de recherche

int est_vide(arbre a);

node new_node(node FG, int value, node FD);

node FG(node n);

node FD(node n);

int key(node n);

void print_node(node n);

//Partie pour les arbres binaire de recherche

void inserer_ABR(node elem, ABR abr);

void supprimer_value(int value, ABR abr);

int supprimer_racine(ABR abr);

int min(ABR abr);