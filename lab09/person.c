#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ορισμός της δομής person
struct person {
    char *fname; // Όνομα
    char *lname; // Επώνυμο
    char *mname; // Πατρώνυμο
};

// Συνάρτηση που αρχικοποιεί ένα άτομο
struct person *person_init(char *firstname, char *lastname, char *middlename) {
    struct person *p = (struct person *)malloc(sizeof(struct person));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    p->fname = strdup(firstname);
    p->lname = strdup(lastname);
    p->mname = strdup(middlename);
    return p;
}

// Συνάρτηση που δημιουργεί τα στοιχεία ενός παιδιού
struct person *childof(struct person father, char *newname) {
    struct person *child = (struct person *)malloc(sizeof(struct person));
    if (child == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    child->fname = strdup(newname);
    child->lname = strdup(father.lname);
    child->mname = strdup(father.fname);
    return child;
}

// Παράδειγμα χρήσης
int main() {
    // Δημιουργία του πατέρα
    struct person *father = person_init("George", "Smith", "Michael");
    printf("Father: %s %s (%s)\n", father->fname, father->lname, father->mname);

    // Δημιουργία του παιδιού
    struct person *child = childof(*father, "John");
    printf("Child: %s %s (%s)\n", child->fname, child->lname, child->mname);

    // Απελευθέρωση μνήμης
    free(father->fname);
    free(father->lname);
    free(father->mname);
    free(father);

    free(child->fname);
    free(child->lname);
    free(child->mname);
    free(child);

    return 0;
}
