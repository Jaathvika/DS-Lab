// Experiment 16: Implementation of Polynomial Addition using Linked List

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
    Term *n = createTerm(coeff, exp);
    if (!*poly || (*poly)->exp < exp) { n->next = *poly; *poly = n; return; }
    Term *t = *poly;
    while (t->next && t->next->exp > exp) t = t->next;
    n->next = t->next; t->next = n;
}

void displayPoly(Term *poly) {
    if (!poly) { printf("0\n"); return; }
    while (poly) {
        if (poly->coeff >= 0 && poly != NULL) printf("+");
        if (poly->exp == 0) printf("%.1f", poly->coeff);
        else if (poly->exp == 1) printf("%.1fx", poly->coeff);
        else printf("%.1fx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly) printf(" ");
    }
    printf("\n");
}

Term* addPolynomials(Term *p1, Term *p2) {
    Term *result = NULL;
    while (p1 && p2) {
        if (p1->exp > p2->exp) { insertTerm(&result, p1->coeff, p1->exp); p1 = p1->next; }
        else if (p2->exp > p1->exp) { insertTerm(&result, p2->coeff, p2->exp); p2 = p2->next; }
        else {
            float sum = p1->coeff + p2->coeff;
            if (sum != 0) insertTerm(&result, sum, p1->exp);
            p1 = p1->next; p2 = p2->next;
        }
    }
    while (p1) { insertTerm(&result, p1->coeff, p1->exp); p1 = p1->next; }
    while (p2) { insertTerm(&result, p2->coeff, p2->exp); p2 = p2->next; }
    return result;
}

int main() {
    Term *poly1 = NULL, *poly2 = NULL;
    int n; float coeff; int exp;

    printf("=== Polynomial Addition using Linked List ===\n");

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

    printf("\nPolynomial 1: "); displayPoly(poly1);
    printf("Polynomial 2: "); displayPoly(poly2);

    Term *result = addPolynomials(poly1, poly2);
    printf("Sum:          "); displayPoly(result);

    return 0;
}
