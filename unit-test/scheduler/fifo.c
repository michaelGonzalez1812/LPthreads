/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *     Test FIFO scheduler
 * ***********************************************************/


#include <package.h>
#include <scheduler.h>

int main(int argc, char** argv) {

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


    for(int i=0;i < 12; i++){
         int id = queue[i].id;
         int wght = queue[i].weight;
         int type = queue[i].type;

         printf("Pkg id: %d wght: %d type: %d\n",id,wght,type);
    }

    package_t* result;
    result = get_next_item(queue, &queue_count, 3);
    printf("Extracted Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    result = get_next_item(queue, &queue_count, 3);
    printf("Extracted Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    result = get_next_item(queue, &queue_count, 3);
    printf("Extracted Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    result = get_next_item(queue, &queue_count, 3);
    printf("Extracted Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    result = get_next_item(queue, &queue_count, 3);
    printf("Extracted Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    result = get_next_item(queue, &queue_count, 3);
    printf("Extracted Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    result = get_next_item(queue, &queue_count, 3);
    printf("Extracted Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    result = get_next_item(queue, &queue_count, 3);
    printf("Extracted Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    result = get_next_item(queue, &queue_count, 3);
    printf("Extracted Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    result = get_next_item(queue, &queue_count, 3);
    printf("Extracted Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    result = get_next_item(queue, &queue_count, 3);
    printf("Extracted Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);
    result = get_next_item(queue, &queue_count, 3);
    printf("Extracted Pkg id: %d wght: %d type: %d\n",result->id,result->weight,result->type);

    return 0;
}