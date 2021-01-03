typedef struct elem *elem;

struct elem
{
    int value;
    elem suivant;
};

typedef struct file *file;

struct file
{
    elem tete;
    elem queue;
};

file file_vide(void);

int est_vide(file f);

void enfiler(int value, file f);

elem tete(file f);

int defiler(file f);

void detruire_file(file f);