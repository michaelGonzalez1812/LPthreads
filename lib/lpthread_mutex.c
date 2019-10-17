/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      Implementation of lpthread_mutex library
 * ***********************************************************/

#include <lpthread_mutex.h>

void lmutex_init(lpthread_mutex **mutex) {
    *mutex = (lpthread_mutex*) malloc(sizeof(lpthread_mutex));
    atomic_flag_clear(mutex);
}

void lmutex_destroy(lpthread_mutex *mutex) {
    free((void*) mutex);
}

void lmutex_unlock(lpthread_mutex *mutex) {
    atomic_flag_clear(mutex);
}

void lmutex_trylock(lpthread_mutex *mutex) {
    while (atomic_flag_test_and_set(mutex) == true);
}