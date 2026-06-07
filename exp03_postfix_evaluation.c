// Experiment 17: Implementation of Polynomial Multiplication using Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    float coeff;
    int exp;
    struct Term *next;
} Term;

Term* createTerm(float coeff, int exp) {
    Term *t = (Term*)malloc(sizeof(Term));
    t->coeff = coeff; t->exp = exp; t->next = NULL;
    return t;
}

void insertTerm(Term **poly, float coeff, int exp) {
    // Check if term with same exp exists
    Term *t = *poly;
    while (t) {
        if (t->exp == exp) { t->coeff += coeff; return; }
        t = t->next;
    }
    // Insert in descending order of exp
    Term *n = createTerm(coeff, exp);
    if (!*poly || (*poly)->exp < exp) { n->next = *poly; *poly = n; return; }
    t = *poly;
    while (t->next && t->next->exp > exp) t = t->next;
    n->next = t->next; t->next = n;
}

void displayPoly(Term *poly) {
    if (!poly) { printf("0\n"); return; }
    int first = 1;
    while (poly) {
        if (!first && poly->coeff >= 0) printf("+");
        if (poly->exp == 0) printf("%.1f", poly->coeff);
        else if (poly->exp == 1) printf("%.1fx", poly->coeff);
        else printf("%.1fx^%d", poly->coeff, poly->exp);
        poly = poly->next; first = 0;
        if (poly) printf(" ");
    }
    printf("\n");
}

Term* multiplyPolynomials(Term *p1, Term *p2) {
    Term *result = NULL;
    for (Term *t1 = p1; t1; t1 = t1->next)
        for (Term *t2 = p2; t2; t2 = t2->next)
            insertTerm(&result, t1->coeff * t2->coeff, t1->exp + t2->exp);
    return result;
}

int main() {
    Term *poly1 = NULL, *poly2 = NULL;
    int n; float coeff; int exp;

    printf("=== Polynomial Multiplication using Linked List ===\n");

    printf("Enter number of terms in Polynomial 1: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("  Term %d - Coefficient: ", i + 1); scanf("%f", &coeff);
        printf("  Term %d - Exponent: ", i + 1); scanf("%d", &exp);
        insertTerm(&poly1, coeff, exp);
    }

    printf("Enter number of terms in Polynomial 2: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("  Term %d - Coefficient: ", i + 1); scanf("%f", &coeff);
        printf("  Term %d - Exponent: ", i + 1); scanf("%d", &exp);
        insertTerm(&poly2, coeff, exp);
    }

    printf("\nPolynomial 1:  "); displayPoly(poly1);
    printf("Polynomial 2:  "); displayPoly(poly2);

    Term *result = multiplyPolynomials(poly1, poly2);
    printf("Product:       "); displayPoly(result);

    return 0;
}
