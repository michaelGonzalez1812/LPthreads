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
#define PRIORIRY_SCHE    1
#define SJF_SCHE         2  //shortest job first
#define FIFO_SCHE        3
#define RT_SCHE          4   //Real time

/*************************************************************
 * Description:
 *      Select the next pkg to be processes depending on the 
 *      sche type
 * 
 * parameters:
 *      queue -> array with elements
 *      queue_count -> Quanty elements in the array
 *      sche -> Scheduler policy
 *      itm_index (return too) -> itm pos in the array
 * 
 * return:
 *      ptr to the elemente Selected
 * ***********************************************************/
package_t* get_next_item(package_t *queue, int *queue_count, int sche);


package_t* round_robin_sche(package_t *queue, int queue_count, int *itm_index);

package_t* sjf_sche(package_t *queue, int queue_count, int *itm_index);

package_t* fifo_sche(package_t *queue, int queue_count, int *itm_index);

package_t* rt_sche(package_t *queue, int queue_count, int *itm_index);

void rmv_pkg(int itm_index, package_t *queue, int queue_count);

#endif