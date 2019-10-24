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

void pkg_init(package_t *pkg, int *pkg_id_counter) {
    pkg -> id = *pkg_id_counter;
    (*pkg_id_counter)++;
    //avoid a weight of zero
    int flag = 1;
    int temp_wght;

    while (flag) {
        srand(time(0));
        temp_wght = rand() % 10;
        if (temp_wght != 0) {
            pkg -> weight = temp_wght;
            flag = 0;
        }
    }
    
    //TODO: function to get the type given the confg file  
    pkg -> type = 0;
}

float compute_time(int pkg_weight) {

    //TODO: not implemented yet
    
    return 16;
}

int get_side(){
    srand(time(0));
    return rand() % 2;
}

int get_qntty(){
    //TODO: read distribution from config file
    
    //Hardwired distribution
    int const array_size = 48;
    int arr[] = {7, 6, 5, 5,
                 4, 4, 4, 3,
                 3, 3, 3, 2,
                 2, 2, 1, 1,
                 1, 1, 1, 1,
                 0, 0, 0, 0, 
                 0, 0, 0, 1,
                 1, 1, 1, 1,
                 1, 2, 2, 2,
                 2, 3, 3, 3,
                 3, 4, 4, 4,
                 5, 5, 6, 7};
    
    return arr[rand() % array_size + 1];
}