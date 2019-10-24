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
        (sche == PRIORIRY_SCHE)    ? priority_sche(queue, *queue_count, &itm_index)        : 
                                     rt_sche(queue, *queue_count, &itm_index);

    rmv_pkg(itm_index, queue, *queue_count);
    *queue_count--;
    return result;
}

package_t* round_robin_sche(package_t *queue, int queue_count, int *itm_index) {
    srand(time(0));
    int index = rand() % queue_count;
    *itm_index = index;
    return &queue[index];
}

package_t* sjf_sche(package_t *queue, int queue_count, int *itm_index) {
    int current_short = 0;//index of the shortest job aka less weight
    for(int i=1;i<queue_count;i++){
        if (queue[current_short].weight > queue[i].weight){
            current_short = i;
        }
    }
    *itm_index = current_short;
    return &queue[current_short];
}

package_t* fifo_sche(package_t *queue, int queue_count, int *itm_index) {
    *itm_index = 0;
    return &queue[0];
}

package_t* priority_sche(package_t *queue, int queue_count, int *itm_index) {
    int current_prior = 0;//index of the highest priority
    for(int i=0;i<queue_count;i++){
        if (queue[current_short].type > queue[i].type){
            current_short = i;
        }
    }
    *itm_index = current_short;
    return &queue[current_short];
}

package_t* rt_sche(package_t *queue, int queue_count, int *itm_index) {
//TODO
}

void rmv_pkg(int itm_index, package_t *queue, int queue_count) {
    for (int i = itm_index; i < queue_count-1 ; i++){
        queue[i]=queue[i+1];
    }
}