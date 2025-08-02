#include <stdio.h>
#include <stdlib.h>

typedef struct poly {
    int coeff;  
    int exp;   
    struct poly *link;  
} poly;

poly* create_poly(poly *p) {
    int ch;
    poly *new_node, *last;
    do {
        new_node = (poly*)malloc(sizeof(poly));
        printf("Enter the coefficient and exponent: ");
        scanf("%d %d", &new_node->coeff, &new_node->exp);
        new_node->link = NULL;

        if (p == NULL) {
            p = new_node;
            last = new_node;
        } else {
            last->link = new_node;
            last = new_node;
        }

        printf("Enter your choice:\n");
        printf("1: for creation of another node\n");
        printf("0: to stop\n");
        scanf("%d", &ch);
    } while (ch != 0);

    return p;
}

void display_poly(poly *p) {
    while (p != NULL) {
        printf("%dx^%d", p->coeff, p->exp);
        p = p->link;
        if (p != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

poly* add_polys(poly *p1, poly *p2) {
    poly *p3 = NULL, *last = NULL, *new_node;

    while (p1 != NULL && p2 != NULL) {
        new_node = (poly*)malloc(sizeof(poly));
        new_node->link = NULL;

        if (p1->exp > p2->exp) {
            new_node->coeff = p1->coeff;
            new_node->exp = p1->exp;
            p1 = p1->link;
        } else if (p1->exp < p2->exp) {
            new_node->coeff = p2->coeff;
            new_node->exp = p2->exp;
            p2 = p2->link;
        } else {
            new_node->coeff = p1->coeff + p2->coeff;
            new_node->exp = p1->exp;
            p1 = p1->link;
            p2 = p2->link;
        }

        if (p3 == NULL) {
            p3 = new_node;
            last = new_node;
        } else {
            last->link = new_node;
            last = new_node;
        }
    }

    while (p1 != NULL) {
        new_node = (poly*)malloc(sizeof(poly));
        new_node->coeff = p1->coeff;
        new_node->exp = p1->exp;
        new_node->link = NULL;

        if (p3 == NULL) {
            p3 = new_node;
            last = new_node;
        } else {
            last->link = new_node;
            last = new_node;
        }
        p1 = p1->link;
    }

    while (p2 != NULL) {
        new_node = (poly*)malloc(sizeof(poly));
        new_node->coeff = p2->coeff;
        new_node->exp = p2->exp;
        new_node->link = NULL;

        if (p3 == NULL) {
            p3 = new_node;
            last = new_node;
        } else {
            last->link = new_node;
            last = new_node;
        }
        p2 = p2->link;
    }

    return p3;
}

int main() {
    poly *p1 = NULL, *p2 = NULL, *p3 = NULL;

    printf("Creating the first polynomial:\n");
    p1 = create_poly(p1);

    printf("Creating the second polynomial:\n");
    p2 = create_poly(p2);

    printf("First Polynomial: ");
    display_poly(p1);

    printf("Second Polynomial: ");
    display_poly(p2);

    p3 = add_polys(p1, p2);

    printf("Resultant Polynomial after addition: ");
    display_poly(p3);

    return 0;
}
