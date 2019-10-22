/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      Implementation of lpthread library
 * ***********************************************************/

#include <lpthread.h>

#include <band.h>

#define NUM_BANDS 3

int main(int argc, char** argv) {

    // printf("init...\n");
    
    // band_t *bands = malloc(3*sizeof(band_t));
    // int thread_ids[NUM_BANDS];
    // int bands_count = 0;

    // for (int i = 0; i <= NUM_BANDS; i++) {
    //     band_init(&bands[i], FIFO_SCHE, &bands_count);
    //     // printf("on transporter: Band sche is %d\n", &bands[i]->sche_type);
    //     thread_ids[i] = lpthread_create(do_in_background, (char*) &bands[i]);
    // }

    // for (int i = 0; i <= NUM_BANDS; i++)
    //     lpthread_join(thread_ids[i]);

    // printf("exiting...\n\n");
    

    band_t *band1_ptr = malloc(sizeof(band_t));
    int thread_id;
    int bands_count = 0;

    band_init(band1_ptr,FIFO_SCHE,&bands_count);
    thread_id = lpthread_create(do_in_background,(char*) band1_ptr);

    lpthread_join(thread_id);

    printf("exiting...\n\n");

    return 0;
}