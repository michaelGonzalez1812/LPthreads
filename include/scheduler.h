/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      scheduler library 
 * ***********************************************************/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <package.h>

/***********************************
 * Scheduling types
 * *********************************/
#define ROUND_ROBIN_SCHE 0
#define SJF_SCHE         1  //shortest job first
#define FIFO_SCHE        2
#define RT_SCHE          3   //Real time

typedef struct {
    int count;
    int size;
    //must be the ready queue
    package_t *queue_begin;
} queue_t;

package_t* get_next_item(queue_t *queue, int sche);

#endif