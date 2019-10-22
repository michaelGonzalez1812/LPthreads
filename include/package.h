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
#define PACKAGE_H

#include <stdlib.h>

#define NORMAL_PKG 0
#define URGENT_PKG 1
#define RADIOACTIVE_PKG 2

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
void pkg_init(package_t *pkg, int *pkg_counter);

/*************************************************************
 * Description:
 *      Create new packages
 * Parameters:
 * return:
 *      Ptr to the array of new packages
 * ***********************************************************/
package_t* generate_pkgs(int *pkg_counter);

/*************************************************************
 * Description:
 *      Compute time to pass through
 * Parameters:
 *      pkg_mole -> 
 * return:
 *       Time to pass through the band
 * ***********************************************************/
float compute_time(int pkg_mole);


/*************************************************************
 * Description:
 *      Decides wich side the pkg will be assigned to
 * Parameters:
 *     
 * return:
 *      0 -> left
 *      1 -> right
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


/*************************************************************
 * Description:
 *      get random number (auxiliar)
 * Parameters:
 *      range: the top of the range for the return value
 * return:
 *      number between 0 and range
 * ***********************************************************/
int get_random(int range);

#endif