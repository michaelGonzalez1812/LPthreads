/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      Packages library implementation
 * ***********************************************************/

#include <package.h>

void pkg_init(package_t *pkg, int *pkg_counter) {
    pkg->id = *pkg_counter++;
}

float compute_time(int pkg_mole) {

    //TODO: not implemented yet
    
    return 0;
}