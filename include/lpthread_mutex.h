/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      This library implements basics synchronization
 *      methods to kernel threads
 * ***********************************************************/

#ifndef LPTHREAD_MUTEX_H
#define LPTHREAD_MUTEX_H

#include <stdatomic.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdatomic.h>
#include <stdbool.h>


/**************************************************************
 * Definition of lpthread_mutex type
 * ************************************************************/
typedef volatile atomic_flag lpthread_mutex;

/*************************************************************
 * Description:
 *      Initialize the mutex
 * Parameters:
 *      mutex -> Pointer to the pointer of the mutex variable
 * return:
 * ***********************************************************/
void lmutex_init(lpthread_mutex **mutex);

/*************************************************************
 * Description:
 *      Free the mutex memory allocation
 * Parameters:
 *      mutex -> Pointer to the mutex
 * return:
 * ***********************************************************/
void lmutex_destroy(lpthread_mutex *mutex);

/*************************************************************
 * Description:
 *      Unlock mutex
 * Parameters:
 *      mutex -> Pointer to de pointer of the mutex variable
 * return:
 * ***********************************************************/
void lmutex_unlock(lpthread_mutex *mutex);

/*************************************************************
 * Description:
 *      Try to lock the mutex. If the mutex is already lock
 *      then it waits until it can acquire the mutex
 * Parameters:
 *      mutex -> Pointer to de pointer of the mutex variable
 * return:
 * ***********************************************************/
void lmutex_trylock(lpthread_mutex *mutex);

#endif