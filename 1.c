#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coeff;
    int exp;
} Term;

typedef struct {
    Term terms[201];
    int numTerms;
} Polynomial;

int main() {
    int n;
    scanf("%d", &n);

    Polynomial poly1;
    poly1.numTerms = n;
    for (int i = 0; i < 201; i++)
        poly1.terms[i].coeff = 0, poly1.terms[i].exp = i;

    for (int i = 0; i < n; i++) {
        int coeff;
        int exp;
        scanf("%d %d", &coeff, &exp);
        poly1.terms[exp].coeff = coeff;
    }

    int m;
    scanf("%d", &m);

    Polynomial poly2;
    poly2.numTerms = m;
    for (int i = 0; i < 201; i++)
        poly2.terms[i].coeff = 0, poly2.terms[i].exp = i;

    for (int i = 0; i < m; i++) {
        int coeff;
        int exp;
        scanf("%d %d", &coeff, &exp);
        poly2.terms[exp].coeff = coeff;
    }

    for (int i = 100; i >= 0; i--) {
        if (poly1.terms[i].coeff != 0 || poly2.terms[i].coeff != 0)
            printf("(%d,%d) ", poly1.terms[i].coeff + poly2.terms[i].coeff, i);
    }
    printf("\n");

    Polynomial poly3;
    poly3.numTerms = m * n;
    for (int i = 0; i < 201; i++)
        poly3.terms[i].coeff = 0, poly3.terms[i].exp = i;

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++)
            poly3.terms[i + j].coeff += (poly1.terms[i].coeff * poly2.terms[j].coeff);
    }

    for (int i = 200; i >= 0; i--) {
        if (poly3.terms[i].coeff != 0)
            printf("(%d,%d) ", poly3.terms[i].coeff, i);
    }

    return 0;
}
