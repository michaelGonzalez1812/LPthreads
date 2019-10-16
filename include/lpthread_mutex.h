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

int lmutex_init();

int lmutex_destroy();

int lmutex_unlock();

int lmutex_trylock();

#endif