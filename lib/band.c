/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      Band library implementation
 * ***********************************************************/

#include <band.h>

void mov_package(package_t *pkg, int dir) {
    int pos = 0;
    if (dir == 1){
        pos = 1;
    }
    
    update_file(pkg->id, pos, pkg->type);
    int time = compute_time(pkg->weight);
    time /= 8;
    while (pos < 8) {
        sleep(time);
        pos++;
        update_file(pkg->id, pos, pkg->id);
    }
    //TODO: cuando termina elimina paquete
}


int do_in_background(void *arg) {

    if (arg == NULL) {
        printf("The band must be specified\n");
        return -1;
    }
    band_t *band = (band_t*) arg;
    
    // List of new pkgs 
    package_t *new_pkgs;
    //next pkg to move
    package_t *next_pkg;

    
    int direction;// flux for the packages
    int side; //wich side of the band will the packages go
    band->on = true;
    printf("Band %d working!\n", band->id);

    int pkg_counter = 0;

    while(band->on) {
        int new_pkg_size;
        new_pkgs = generate_pkgs(&pkg_counter, &new_pkg_size);
        
        //TODO: add new elements to the queue
        side = get_side();
        printf("side is = %d\n",side);
        add_packages(new_pkgs, new_pkg_size, side, band);

        printf("Band L pkgs size is %d\n", band-> left_pkgs_count);
        printf("Band R pkgs size is %d\n", band-> right_pkgs_count);

        
        // direction = get_dir(band);
        // next_pkg = (direction == LEFT_TO_RIGHT) ? 
        //         get_next_item(band->left_pkgs_queue, band->sche_type) : 
        //         get_next_item(band->right_pkgs_queue, band->sche_type);
        
        // mov_package(next_pkg, direction);
        band->on = false;
    }

    return 0;
}

void add_packages(package_t *new_pkgs, int amount, int side, band_t *band){
    int pkg_count; //total size resulting from adding the new pkgs to the array
    int current_size;   //current size of array of pkgs in the band 
    package_t **band_pkgs_ptr; // ponter to the pointer with the list of pkgs
    int *count; //pointer to the counter of packages on the band side
    if ( side == 0 ){// add to left
        current_size = band -> left_pkgs_count;
        pkg_count = current_size + amount;
        band_pkgs_ptr = &band -> left_pkgs_queue;
        count = &band -> left_pkgs_count;
    } else{ //add to right
        current_size = band -> right_pkgs_count;
        pkg_count = current_size + amount;
        band_pkgs_ptr = &band -> right_pkgs_queue;
        count = &band -> right_pkgs_count;
    }
    
    if (pkg_count<INITIAL_queue_SIZE){//no need to re-allocate  
        int j = 0;
        for(int i=current_size; i < pkg_count;i++){
            printf("add pkg, enter for i = %d\n",i);
            *band_pkgs_ptr[i]= new_pkgs[j];
            printf("add pkg, band pkg wght [i] is %d\n", band_pkgs_ptr[i]->weight);
            *count = *count + 1;
            printf("add pkg, count is %d\n", *count);
            j++;
        }
    }
    else{ // need to reallocate
        printf("TODO: need re-allocation\n");

    }


}


void turn_off_band(band_t *band) { band->on = false; }

void band_init(band_t *band, int sche, int *bands_count) {
    
    band -> id = *bands_count;
    *bands_count++;
    band -> sche_type = sche;
    band -> left_pkgs_queue = malloc(INITIAL_queue_SIZE*sizeof(package_t));
    band -> right_pkgs_queue = malloc(INITIAL_queue_SIZE*sizeof(package_t));
    band -> left_pkgs_count = 0;
    band -> right_pkgs_count = 0;
    band -> on = false;
    band -> dir = 0;
    
    int flux_from_file = 0; //Default: sign
    //TODO: Agarrar tipo de flujo del archivo de configuracion
    // flux_from_file = functionToGetDataFromFile("flux"); // argument to indicate wich parameter to get. In this case, the flux type  
    band -> flux_type = flux_from_file;
    // printf("on init: Band sche is %d\n", band->sche_type);
}

int get_dir(band_t *band) {
    return band -> dir;
}

int update_file(int pkg_id, int pos, int pkg_type) {
    printf("Performing movement of package %d of type %d to %d  \n", pkg_id, pos, pkg_type);
    //TODO: not implemented yet

    return 0;
}