#include <stdio.h>
#include <stdlib.h>

int global_var1 = 1;
int global_var2 = 2;
int global_var3 = 3;

void heap4();void heap3();void heap2();void heap1();
void stack3();void stack2();void stack1();
int global1();

void heap4() {
    int *heap_var4 = (int *)malloc(sizeof(int));
    *heap_var4 = 300;
    printf("Address of heap_var4 allocated by malloc (heap): %p\n", (void*)heap_var4);

    free(heap_var4);
}

void heap3() {
    int *heap_var3 = (int *)malloc(sizeof(int));
    *heap_var3 = 300;
    printf("Address of heap_var3 allocated by malloc (heap): %p\n", (void*)heap_var3);

    heap4();
    free(heap_var3);
}

void heap2() {
    int *heap_var2 = (int *)malloc(sizeof(int));
    *heap_var2 = 200;
    printf("Address of heap_var2 allocated by malloc (heap): %p\n", (void*)heap_var2);

    heap3(); 
    free(heap_var2);
}

void heap1() {
    int *heap_var1 = (int *)malloc(sizeof(int));
    *heap_var1 = 100;
    printf("Address of heap_var1 allocated by malloc (heap): %p\n", (void*)heap_var1);
    
    heap2(); 
    free(heap_var1);
}

void stack3() {
    int local_var3 = 3;
    printf("Address of local_var3 (stack): %p\n", (void*)&local_var3);
}

void stack2() {
    int local_var2 = 2;
    printf("Address of local_var2 (stack): %p\n", (void*)&local_var2);

    stack3(); 
}

void stack1() {
    int local_var1 = 1;
    printf("Address of local_var1 (stack): %p\n", (void*)&local_var1);

    stack2(); 
}

int global1() {
    printf("Address of global_var1 (global): %p\n", (void*)&global_var1);
    printf("Address of global_var2 (global): %p\n", (void*)&global_var2);
    printf("Address of global_var3 (global): %p\n", (void*)&global_var3);
    return 0;
}

int main() {
    global1();
    stack1(); 
    heap1();
    return 0;
}