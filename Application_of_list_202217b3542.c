#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coefficient;
    int exponent;
} PolynomialTerm;

typedef struct {
    PolynomialTerm *terms;
    int size;
} Polynomial;

// Function to create a polynomial
Polynomial create_polynomial(int num_terms) {
    Polynomial poly;
    poly.size = num_terms;
    poly.terms = (PolynomialTerm *)malloc(num_terms * sizeof(PolynomialTerm));
    return poly;
}

// Function to add a term to a polynomial
void add_term(Polynomial *poly, int coefficient, int exponent, int index) {
    poly->terms[index].coefficient = coefficient;
    poly->terms[index].exponent = exponent;
}

// Function to add two polynomials
Polynomial add_polynomials(Polynomial poly1, Polynomial poly2) {
    Polynomial result;
    result.size = poly1.size + poly2.size; // Maximum possible size
    result.terms = (PolynomialTerm *)malloc(result.size * sizeof(PolynomialTerm));
    
    int i = 0, j = 0, k = 0;

    while (i < poly1.size && j < poly2.size) {
        if (poly1.terms[i].exponent == poly2.terms[j].exponent) {
            // Add coefficients if exponents are the same
            int new_coefficient = poly1.terms[i].coefficient + poly2.terms[j].coefficient;
            if (new_coefficient != 0) {
                add_term(&result, new_coefficient, poly1.terms[i].exponent, k++);
            }
            i++;
            j++;
        } else if (poly1.terms[i].exponent > poly2.terms[j].exponent) {
            add_term(&result, poly1.terms[i].coefficient, poly1.terms[i].exponent, k++);
            i++;
        } else {
            add_term(&result, poly2.terms[j].coefficient, poly2.terms[j].exponent, k++);
            j++;
        }
    }

    // Add remaining terms from poly1
    while (i < poly1.size) {
        add_term(&result, poly1.terms[i].coefficient, poly1.terms[i].exponent, k++);
        i++;
    }

    // Add remaining terms from poly2
    while (j < poly2.size) {
        add_term(&result, poly2.terms[j].coefficient, poly2.terms[j].exponent, k++);
        j++;
    }

    // Resize result to the actual number of terms
    result.size = k;
    result.terms = (PolynomialTerm *)realloc(result.terms, k * sizeof(PolynomialTerm));
    
    return result;
}

// Function to display a polynomial
void display_polynomial(Polynomial poly) {
    for (int i = 0; i < poly.size; i++) {
        if (i > 0 && poly.terms[i].coefficient > 0) {
            printf(" + ");
        }
        printf("%dx^%d", poly.terms[i].coefficient, poly.terms[i].exponent);
    }
    printf("\n");
}

// Function to input a polynomial
Polynomial input_polynomial() {
    int num_terms;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &num_terms);
    
    Polynomial poly = create_polynomial(num_terms);
    for (int i = 0; i < num_terms; i++) {
        printf("Enter coefficient: ");
        scanf("%d", &poly.terms[i].coefficient);
        printf("Enter exponent: ");
        scanf("%d", &poly.terms[i].exponent);
    }
    return poly;
}

// Main function
int main() {
    printf("Input for the first polynomial:\n");
    Polynomial poly1 = input_polynomial();
    
    printf("Input for the second polynomial:\n");
    Polynomial poly2 = input_polynomial();
    
    Polynomial result_poly = add_polynomials(poly1, poly2);
    
    printf("The sum of the polynomials is: ");
    display_polynomial(result_poly);
    
    // Free allocated memory
    free(poly1.terms);
    free(poly2.terms);
    free(result_poly.terms);
    
    return 0;
}