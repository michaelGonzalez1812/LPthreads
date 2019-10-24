/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      scheduler library implementation
 * ***********************************************************/

#include <scheduler.h>

package_t* get_next_item(package_t *queue, int *queue_count, int sche) {
    
    int itm_index;
    package_t* result = 
        (sche == ROUND_ROBIN_SCHE) ? round_robin_sche(queue, *queue_count, &itm_index) :
        (sche == SJF_SCHE)         ? sjf_sche(queue, *queue_count, &itm_index)         :
        (sche == FIFO_SCHE)        ? fifo_sche(queue, *queue_count, &itm_index)        : 
                                     rt_sche(queue, *queue_count, &itm_index);

    //not needed para fifo
    //rmv_pkg(itm_index, queue, *queue_count);
    *queue_count--;
    return result;
}

package_t* round_robin_sche(package_t *queue, int queue_count, int *itm_index) {

}

package_t* sjf_sche(package_t *queue, int queue_count, int *itm_index) {

}

package_t* fifo_sche(package_t *queue, int queue_count, int *itm_index) {
    *itm_index = queue_count - 1;
    return &queue[*itm_index]; 
}

package_t* rt_sche(package_t *queue, int queue_count, int *itm_index) {

}

void rmv_pkg(int itm_index, package_t *queue, int queue_count) {

}