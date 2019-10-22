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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void pkg_init(package_t *pkg, int *pkg_counter) {
    pkg->id = *pkg_counter++;
}

float compute_time(int pkg_mole) {

    //TODO: not implemented yet
    
    return 0;
}


package_t* generate_pkgs(int *pkg_counter){
    //TODO: to be implemented
    int side = get_side();
    int qntty = get_qntty();
    printf("on gen package: quantity is %d\n", qntty);
    return 0;

    //asi se hace la llamada para inicializar paquetes
    package_t pkg;
    pkg_init(&pkg, pkg_counter);

    return NULL;
}

int get_side(){
    int side = get_random(2);

}

int get_qntty(){
    //TODO: read distribution from config file
    //Hardwired distribution
    int arr[] = {7,6,5,5,4,4,4,3,3,3,3,2,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,4,4,5,6,7};
    int index = get_random((sizeof(arr)/sizeof(*arr)));
    //printf("on qtty: rndm is %d\n", (sizeof(arr)/sizeof(*arr)));
    int qntty = arr[index];
    
}



int get_random(int range){
    srand(time(NULL));
    int r = rand() % range;
    return r;
}