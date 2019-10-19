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
    int mole;   //pkg mole(masa)
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
 *      Compute time to pass through
 * Parameters:
 *      pkg_mole -> 
 * return:
 *       Time to pass through the band
 * ***********************************************************/
float compute_time(int pkg_mole);

#endif