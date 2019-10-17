/********************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 * *****************************************************************/

#include <lpthread.h>
#include <lpthread_mutex.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdatomic.h>
#include <stdatomic.h>
#include <stdbool.h>


int counter;
lpthread_mutex *lock;

static int trythis(void *arg) 
{ 
    lmutex_trylock(lock); 

    unsigned long i = 0; 
    counter += 1; 
    
    printf("Job %d has started\n", counter); 
    for(i=0; i<(0xFFFFFFFF);i++); 
    printf("Job %d has finished\n", counter); 
  
    lmutex_unlock(lock); 
  
    return 0; 
}

int main(int argc, char** argv) {
    
    lmutex_init(&lock);

    int lpthread_id1 = lpthread_create(trythis, NULL);
    int lpthread_id2 = lpthread_create(trythis, NULL);

    lpthread_join(lpthread_id1);
    lpthread_join(lpthread_id2);

    //TODO: destroy lock

    printf("\nexiting...\n"); 

    return 0;
}
