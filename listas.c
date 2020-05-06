/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: joseh
 *
 * Created on 4 de mayo de 2020, 21:38
 */

#include <stdio.h>
#include <stdlib.h>

// Estructura elementos 
typedef struct _Element {
    int key;                // Clave
    struct _Element* next;  // Puntero a elemento siguiente
} Element;

// Inicializacion de lista (Creador)
void inicialize_list (Element** p_head, Element** p_tail) {
    *p_head = NULL;
    *p_tail = NULL;
}

// Añadir al principio de la lista
void add_first(Element** p_head, Element** p_tail, int value) {
    // Reserva memoria para el nuevo elemento 
    Element* new_element = malloc(sizeof(Element));   
    
    new_element->key = value;       // Carga dato en el elemento
    new_element->next = *p_head;    // Carga puntero a elemento siguiente
    
    *p_head = new_element;
    
    if (*p_tail==NULL) {
        *p_tail = new_element;
    }
}

// Añadir al final de la lista
void add_last(Element** p_head, Element** p_tail, int value) {
    // Reserva memoria para el nuevo elemento 
    Element* new_element = malloc(sizeof(Element));   
    
    new_element->key = value;       // Carga dato en el elemento
    new_element->next = NULL;    // Carga .............
    
    if (*p_tail==NULL) {
        *p_head = *p_tail = new_element;
    } else {
        (*p_tail)->next = new_element; //OjO parantesis
        *p_tail = new_element;
    }
}

void delete(Element** p_head, Element** p_tail, Element* abolish) {
    //Primera posicion
    if (*p_head==abolish) {
        if (*p_tail==*p_head) {
            *p_head = *p_tail = NULL;
        } else {
            *p_head = (*p_head)->next;
        }
    //Segunda en adelante
    } else {
        Element* prev = *p_head;
        while (prev->next!=abolish) {
            prev = prev->next;
        }
        if (prev->next == *p_tail) {
            *p_tail = prev;
        }
        prev->next = abolish->next;
    }
    //free(abolish);    
}

// Imprimir lista 
void print_list (Element* head) {
    while (head!=NULL) {
        //printf("%d", head->key);
        head = head->next;
    }
}

Element* search(Element* head, int value) {
    while (head!=NULL) {
        if (head->key == value)
            return head;
        head = head->next;
    }
    return NULL;
}

 void insert_pos (Element** p_head, Element** p_tail, Element* pos, int value) {
    // Reserva memoria para el nuevo elemento 
    Element* new_element = malloc(sizeof(Element));   
    
    new_element->key = value;

    //Primera posicion
    if (*p_head==pos) {
        new_element->next = pos;
        //Actualizar puntero al primero
        *p_head = new_element;
    //Ultima Posicion
    } else if (*p_tail==pos) {
        add_last(*p_head, *p_tail, value);
        return;
    //De segunda a penultima
    } else {
        Element* prev = *p_head;
        while (prev->next!=pos) {
            prev = prev->next;
        }
        prev->next = new_element;
        new_element->next = pos;
    }
}

 void insert_ord (Element** p_head, Element** p_tail, int value) {
    // Reserva memoria para el nuevo elemento 
    Element* new_element = malloc(sizeof(Element));   
    
    new_element->key = value;

    //Buscar posicion
    Element* pos = *p_head;
    while (pos->key < value-1 && pos->next!=NULL) {
        pos = pos->next;
    }

    //Primera posicion
    if (*p_head==pos) {
        new_element->next = pos;
        //Actualizar puntero al primero
        *p_head = new_element;
    //Ultima Posicion
    // } else if (*p_tail==pos) {

    //     add_last(*p_head, *p_tail, value);
    //     return;
    //De segunda a penultima
    } else {
        Element* prev = *p_head;
        while (prev->next!=pos) {
            prev = prev->next;
        }
        prev->next = new_element;
        new_element->next = pos;
    }
}

int main(int argc, char** argv) {
    Element* head;
    Element* tail;
    
    inicialize_list(&head, &tail);

    add_first(&head, &tail, 2);
    add_last(&head, &tail, 5);
    add_last(&head, &tail, 6);

    // Insertar
    insert_pos(&head, &tail, head->next, 4);
    insert_pos(&head, &tail, head, 1);
    insert_ord(&head, &tail, 4);
    insert_ord(&head, &tail, 3);
    insert_ord(&head, &tail, 7);

    // Borrar a partir de valor
    Element* pos = search(head, 2);
    delete(&head, &tail, pos);
    delete(&head, &tail, head);
    delete(&head, &tail, tail);

    return 0;

    add_last(&head, &tail, 5);
    add_last(&head, &tail, 4);
    add_last(&head, &tail, 6);

    print_list(head);
    return 0;
}
