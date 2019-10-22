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
#include <package.h>

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

    
    int direction;
    band->on = true;
    printf("Band %d working!\n", band->id);

    int pkg_counter = 0;

    while(band->on) {
        //TODO: choose when create pkgs
        new_pkgs = generate_pkgs(&pkg_counter);
        //TODO: add new elements to the queue
        direction = get_dir(band);
        next_pkg = (direction == LEFT_TO_RIGHT) ? 
                get_next_item(band->left_pkgs_queue, band->sche_type) : 
                get_next_item(band->right_pkgs_queue, band->sche_type);
        
        mov_package(next_pkg, direction);
    }

    return 0;
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