/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      Library with the functionality and data structures
 *      to packages
 * ***********************************************************/

#ifndef PACKAGE_H
#define PACKAGE_H    int side = get_side();

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#define NORMAL_PKG 0
#define URGENT_PKG 1
#define RADIOACTIVE_PKG 2

#define LEFT_PKG_SIDE 0
#define RIGHT_PKG_SIDE 1

typedef struct {
    int id;     
    int weight;  //used to calculate time to move it form side to side
    int type;   
} package_t;

/*************************************************************
 * Description:
 *      Initialize the data to work with the pkg
 * Parameters:
 *      pkg to work
 * return:
 *       0 -> success
 *      -1 -> error
 * ***********************************************************/
void pkg_init(package_t *pkg, int *pkg_id_counter);

/*************************************************************
 * Description:
 *      Compute time to pass through
 * Parameters:
 *      pkg_weight -> weight of the package
 * return:
 *       Time to pass through the band
 * ***********************************************************/
float compute_time(int pkg_weight);


/*************************************************************
 * Description:
 *      Decides wich side the pkg will be assigned to
 * Parameters:
 *     
 * return:
 *      0 -> LEFT_PKG_SIDE
 *      1 -> RIGHT_PKG_SIDE
 * ***********************************************************/
int get_side();

/*************************************************************
 * Description:
 *      Gets the number of packages to be generated based on a 
 *      gaussian distribution
 * Parameters:
 *     
 * return:
 *      a number with the qntty to be generated 
 * ***********************************************************/
int get_qntty();


#endif