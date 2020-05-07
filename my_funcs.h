#include <stdio.h>
#include <stdlib.h>

/**
 * Intercambia los valores de dos posiciones de memoria
 */
void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

