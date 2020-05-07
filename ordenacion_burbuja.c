/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ordenacion_burbuja.c
 * Author: joseh
 *
 * Created on 4 de mayo de 2020, 21:38
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <my_funcs.h>

// Imprime el array
int print_array(int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf ("%d ", arr[i]);
    }
}

// Set aleatorio del array entre 10 y 99
int set_array(int arr[], int n) {
    for (int i=0; i<n; i++) {
        arr[i] = 10+rand()%90;
    }
}

/** Intercambia los valores de dos posiciones de memoria
 */
void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

/** Ordenaci�n de la burbuja
 * El siguiente algoritmo itera sobre elementos adyacentes, intercambi�ndolos
 * cuando no se cumple la relaci�n. Esto hace que los elementos menos pesados 
 * suban (bubble up) al principio del array y los m�s pesados caigan (bubble down) 
 * al final del array.
 */
void bubble_sort(int A[], int n) {
    // int a = NULL;
    // int b = NULL;
    int a = NULL;
    int b = NULL;

     // Realiza n-1 iteraciones de burbujeo en la secuencia
     for (int i = 1; i < n; i++) {
           // Burbujea el �ltimo elemento al final
           for (int j = 1; j < n-i+1; j++) {
                 if (A[j-1] > A[j])
                       swap(&A[j-1], &A[j]);
           }
     }
}

void bubble_sort_2() { // Para ver en depurador
    int i, j;
    
    int array[20];
    int n = sizeof(array)/sizeof(int);

    set_array(array, n);

     // Realiza n-1 iteraciones de burbujeo en la secuencia
     for (i = 1; i < n; i++) {
           // Burbujea el �ltimo elemento al final
           for (j = 1; j < n-i+1; j++) {
                 if (array[j-1] > array[j])
                       swap(&array[j-1], &array[j]);
           }
     }
}

/** Ordenaci�n por selecci�n
 * El algoritmo busca el menor de los elementos y lo intercambia 
 * con el primero (suponiendo que no ocupen la misma posici�n, 
 * es decir, que est� ordenado el elemento). En la segunda iteraci�n 
 * busca el segundo elemento m�s peque�o y lo intercambia con el de 
 * la segunda posici�n. El proceso se repite hasta llegar al elemento n-1.
 * */
void selection_sort(int A[], int n) {
    int i, j, min_index, min_value;

    for (i=0;i<n-1;i++) {
        // Almacena la posici�n e �ndice m�nimos
        min_index = i;
        min_value = A[i];
        // B�sca el siguiente m�s peque�o
        for (j=i+1;j<n;j++) {
            if (min_value > A[j]) {
                    min_index = j;
            min_value = A[j];
            }
        }
        if (min_index!=i) {
            swap(&A[i],&A[min_index]);
            }
        }
}

void selection_sort_mio() {
    int i, j;
    
    int A[20];
    int n = sizeof(A)/sizeof(int);

    set_array(A, n);

    printf ("selection_sort_mio\n");
    print_array(A, n);
    printf (":Antes\n");

    int menor, posi_menor;

    for(j=0; j<n-1; j++) {
        posi_menor = j;
        menor=A[posi_menor];
        for(i=j+1; i<=n-1; i++) {
            if (A[i]<menor) {
                menor=A[i];
                posi_menor = i;
            }
        }
        if (posi_menor>j) 
            swap(&A[j], &A[posi_menor]);
    }

    print_array(A, n);
    printf (":Despues\n\n");
}

/** Ordenaci�n por inserci�n
 * El algoritmo divide el array de elementos en dos partes: 
 * los elementos ordenados y los que no lo est�n. Los ordenados 
 * se mantienen al principio y su tama�o va creciendo en cada 
 * iteraci�n.
 * Al empezar, el algoritmo asume que solo el primer elemento 
 * est� ordenado. La variable i es la que separa a los elementos 
 * ordenados de los que no lo est�n, se�alando al primer elemento 
 * no ordenado, que es donde se realizar� la inserci�n.
 */
void insertion_sort(int A[], int n) {
    int i, value, pos;

    // Empieza con el primer elemento como �nico ordenado
    for (i=1; i<n; i++) {
        // value guarda el valor a ser insertado
        value = A[i];
        // Busca pos donde meter el elemento a insertar
        pos = i;
        while (pos>0 && value < A[pos-1]) {
                // Desplaza elemento a la derecha
                A[pos] = A[pos-1];
                pos--;
        }
        // Guarda value en el hueco
        A[pos] = value;
    }
}


void insertion_sort_mio() {
    int i, value, pos;
    
    int A[20];
    int n = sizeof(A)/sizeof(int);

    set_array(A, n);

    printf ("selection_sort_mio\n");
    print_array(A, n);
    printf (":Antes\n");

    for(i=1; i<n; i++) {
        value = A[i];
        pos = i-1;
        while (value<A[pos] && pos>=0) {
            A[pos+1] = A[pos];
            pos--;
        }
        if (value<A[pos]) {
            A[pos] = value;  
        }            
              
    }

    print_array(A, n);
    printf (":Despues\n\n");
}


int main(int argc, char** argv) {
    int i, j;
    
    int array[20];
    int n = sizeof(array)/sizeof(int);
    srand(time(NULL));
    set_array(array, n);

    // bubble_sort
    printf ("bubble_sort\n");
    print_array(array, n);
    printf (":Antes\n");
    bubble_sort(array, n);
    print_array(array, n);
    printf (":Despues\n\n");
    // Ver con debugger
    bubble_sort_2();

    set_array(array, n);

    // bubble_sort
    printf ("bubble_sort\n");
    print_array(array, n);
    printf (":Antes\n");
    selection_sort(array, n);
    print_array(array, n);
    printf (":Despues\n\n");
    // Ver con debugger
    selection_sort_mio();

    set_array(array, n);

    // insertion_sort
    printf ("insertion_sort\n");
    print_array(array, n);
    printf (":Antes\n");
    insertion_sort(array, n);
    print_array(array, n);
    printf (":Despues\n\n");
    // Ver con debugger
    insertion_sort_mio();
    insertion_sort_mio();
    insertion_sort_mio();
    insertion_sort_mio();
    insertion_sort_mio();


}
