/********************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description: Test for the lpthread_yield
 * *****************************************************************/

#include <lpthread.h>

#include <stdlib.h>

int counter;

static int trythis(void *arg) 
{ 
    unsigned long i = 0; 
    counter += 1; 
    
    if (lpthread_yield() == 0)
        printf("Processor yield successfully\n");
    else
        printf("Error on yield\n");

    printf("Job %d has started\n", counter); 
    for(i=0; i<(0xFFFFFFFF);i++); 
    printf("Job %d has finished\n", counter); 
  
    return 0; 
}

int main(int argc, char** argv) {
    
    int lpthread_id1 = lpthread_create(trythis, NULL);
    lpthread_join(lpthread_id1);

    printf("\nexiting...\n"); 

    return 0;
}