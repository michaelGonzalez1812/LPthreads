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

    package_t *selected_pkg = (package_t*) malloc(sizeof(package_t));
    *selected_pkg = *result;
    rmv_pkg(itm_index, queue, *queue_count);

    (*queue_count)--;
    return selected_pkg;
}

package_t* round_robin_sche(package_t *queue, int queue_count, int *itm_index) {
    // srand(time(0));
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
    printf("enter prio\n");
    int high_prior_indx = 0;//index of the highest priority
    int med_prior_indx = 0;//index of the medium priority
    int low_prior_indx = 0;//index of the low priority
    
    int priority_found=0;//indicates the highest level of priority found

    for(int i=0;i<queue_count;i++){//check for pkgs with lowes priority
        if (queue[i].type == 0 && priority_found==0){
            printf("enter low\n");
            low_prior_indx = i;
            continue;
        }
        if (queue[i].type == 1){//check for pkgs with medium priority
            printf("enter med\n");
            med_prior_indx = i;
            priority_found = 1;//overwites found priority
            continue;
        }
        if (queue[i].type == 2){//check for pkgs with highest priority
            printf("enter high\n");
            high_prior_indx = i;
            priority_found = 2;
            break;//if highest priority is found, no need to keep checking
        }
    }

    if (priority_found==2){
        printf("return prio high\n");
        *itm_index = high_prior_indx;
        return &queue[high_prior_indx];
    }
     if (priority_found==1){
          printf("return prio mid\n");
        *itm_index = med_prior_indx;
        return &queue[med_prior_indx];
    }
     printf("return prio low\n");
    *itm_index = low_prior_indx;
    return &queue[low_prior_indx];
}

package_t* rt_sche(package_t *queue, int queue_count, int *itm_index) {
//TODO
}

void rmv_pkg(int itm_index, package_t *queue, int queue_count) {
    for (int i = itm_index; i < queue_count-1 ; i++)
        queue[i] = queue[i+1];
}