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
    pkg -> id = *pkg_counter;
    *pkg_counter=*pkg_counter+1;
    //avoid a weight of zero
    int flag = 1;
    while (flag){
        int temp_wght = get_random(10);
        if (temp_wght!= 0){
            pkg -> weight = temp_wght;
            flag = 0;
        }
    }
    
    //TODO: function to get the type given the confg file  
    pkg -> type = 0;
}

float compute_time(int pkg_weight) {

    //TODO: not implemented yet
    
    return 0;
}


package_t* generate_pkgs(int *pkg_counter, int *size){
    //TODO: to be finished
    srand(time(0));
    int qntty = get_qntty();
    *size = qntty;
    printf("on gen package: quantity is %d\n", qntty);
    if (qntty==0) { return NULL; }
   

    package_t *result = malloc(qntty*sizeof(package_t));
    //Loop to create the defined amount of packages
    
    for (int i =0; i< qntty;i++){
        pkg_init(&result[i], pkg_counter);
    }
    return result;
}

int get_side(){
    srand(time(0));
    int side = get_random(2);
    return side;
}

int get_qntty(){
    //TODO: read distribution from config file
    
    //Hardwired distribution
    int arr[] = {7,6,5,5,4,4,4,3,3,3,3,2,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,4,4,5,6,7};
    
    int index = get_random((sizeof(arr)/sizeof(*arr)));
    int qntty = arr[index];
    return qntty;
}



int get_random(int range){
    int r = rand() % range;
    return r;
}