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
#include <package.h>
#include <scheduler.h>
#include <file_read.h>

#define NUM_BANDS 3

int main(int argc, char** argv) {
    srand(time(0));
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
    
/*
    band_t *band1_ptr = malloc(sizeof(band_t));
    int thread_id;
    int bands_count = 0;

    band_init(band1_ptr,FIFO_SCHE,&bands_count);
    thread_id = lpthread_create(do_in_background,(char*) band1_ptr);

    lpthread_join(thread_id);

    printf("exiting...\n\n");
*/

    band_t band;
    int bands_count = 0;
    band_init(&band, FIFO_SCHE, &bands_count);
    do_in_background((void*) &band);
/*
    package_t p1;
    package_t p2;
    package_t p3;
    package_t p4;
    package_t p5;
    package_t p6;
    package_t p7;
    package_t p8;
    package_t p9;
    package_t p10;
    package_t p11;
    package_t p12;

    p1.id = 0;
    p1.weight = 10;
    p1.type = NORMAL_PKG;

    p2.id = 1;
    p2.weight = 11;
    p2.type = NORMAL_PKG;

    p3.id = 2;
    p3.weight = 12;
    p3.type = NORMAL_PKG;

    p4.id = 3;
    p4.weight = 23;
    p4.type = NORMAL_PKG;

    p5.id = 4;
    p5.weight = 24;
    p5.type = NORMAL_PKG;

    p6.id = 5;
    p6.weight = 185;
    p6.type = URGENT_PKG;

    p7.id = 6;
    p7.weight = 36;
    p7.type = URGENT_PKG;

    p8.id = 7;
    p8.weight = 17;
    p8.type = URGENT_PKG;

    p9.id = 8;
    p9.weight = 48;
    p9.type = RADIOACTIVE_PKG;

    p10.id = 9;
    p10.weight = 5;
    p10.type = NORMAL_PKG;

    p11.id = 10;
    p11.weight = 50;
    p11.type = NORMAL_PKG;
    
    p12.id = 11;
    p12.weight = 25;
    p12.type = RADIOACTIVE_PKG;
    srand(time(0));
    package_t queue[] = {p12,p2,p1,p3,p4,p5,p6,p7,p8,p9,p10,p11};

    int queue_count = 12;
*/
    // package_t* result;
    // result = get_next_item(queue, &queue_count, 0);
    // printf("Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    // result = get_next_item(queue, &queue_count, 0);
    // printf("Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    // result = get_next_item(queue, &queue_count, 0);
    // printf("Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    // result = get_next_item(queue, &queue_count, 0);
    // printf("Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    // result = get_next_item(queue, &queue_count, 0);
    // printf("Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    // result = get_next_item(queue, &queue_count, 0);
    // printf("Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    // result = get_next_item(queue, &queue_count, 0);
    // printf("Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    // result = get_next_item(queue, &queue_count, 0);
    // printf("Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    // result = get_next_item(queue, &queue_count, 0);
    // printf("Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    // result = get_next_item(queue, &queue_count, 0);
    // printf("Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    
    // for(int i=0;i < 12; i++){
    //     int id = queue[i].id;
    //     int wght = queue[i].weight;
    //     int type = queue[i].type;

    //     printf("Pkg id: %d wght: %d type: %d\n",id,wght,type);
    // }



    // const char *filename =  "../config/test.txt";
    
    // parameters_t *parameters = malloc(sizeof(parameters));

    // read_file(filename, parameters_t &parameters);

    return 0;
}