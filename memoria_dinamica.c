

// memoria 0x00000 no se puede acceder
/*
memoria ram, dividida en stack, heap, data etc
heap se encarga el programador
void* puntero a cualquier lado
ojito, al matar un puntero, la variable en el heap queda huerfana
se llama "memory leak"

variables del heap se pueden agrandar

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x = 9;

    int *ptr_x;
    // apunta a la nada, inicializado uwu
    ptr_x = NULL;

    ptr_x = &(x);

    // malloc -> memory allocate. reserva memoria del heap
    // realloc -> redimensiona la memoria reservada en el heap
    // free -> libera memoria

    // por cada malloc, va un free. puedo tener 20000 realloc, no pasa naranja.

    // reservame memoria para un enterito
    // devuelve un void*
    // no sabe que vamos a guardar, por eso el void*. que diga sizeof(int) no significada nada

    // lo casteo a int*
    int *ptr_a_heap = (int *)malloc(2 * sizeof(int)); // recibe tamaño de memoria reservar
    // con el 2 * ahora guarda para 2 enteros

    // 2 formas de entrar a la wea del heap
    *ptr_a_heap = 8;
    // aca es, anda a tu memoria asignada y anda X cantidad de valores hacia delante.
    ptr_a_heap[0] = 9;
    ptr_a_heap[1] = 10;
    // 2 parametros, el segundo es el nuevo tamaño, el primero es la direccion del primer malloc

    // devuelve puntero hacia la posible nueva direccion, puede que sea nueva o puede que sea la misma, intenta que sean contiguas

    ptr_a_heap = realloc(ptr_a_heap, 20 * sizeof(int));

    ptr_a_heap[10] = 30;

    free(ptr_a_heap);

    return 0;
}