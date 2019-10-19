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
    //TODO: tambien puede empezar en el 7 (arreglar)
    int pos = 0;
    update_file(pkg->id, pos, pkg->type);
    int time = compute_time(pkg->mole);
    time /= 8;
    while (pos < 8) {
        sleep(time);
        pos++;
        update_file(pkg->id, pos, pkg->id);
    }
    //TODO: cuando termina elimina paquete
}

package_t* generate_pkgs(int *pkg_counter) {
    //TODO: Not implemented yet
    //asi se hace la llamada para inicializar paquetes
    package_t pkg;
    pkg_init(&pkg, pkg_counter);

    return NULL;
}

int do_in_background(void *arg) {

    if (arg == NULL) {
        printf("The band must be specified\n");
        return -1;
    }
    
    package_t *new_pkgs;
    //next pkg to move
    package_t *next_pkg;
    band_t *band = (band_t*) arg;
    int direction;
    band->on = true;
    printf("Band %d working!\n", band->id);

    int pkg_counter = 0;

    while(band->on) {
        //TODO: choose when create pkgs
        new_pkgs = generate_pkgs(&pkg_counter);
        //TODO: add new elements to the queue
        direction = get_dir();
        next_pkg = (direction == LEFT_TO_RIGHT) ? 
                get_next_item(band->left_pkgs_queue, band->sche_type) : 
                get_next_item(band->right_pkgs_queue, band->sche_type);
        
        mov_package(next_pkg, direction);
    }

    return 0;
}

void turn_of_band(band_t *band) { band->on = false; }

void band_init(band_t *band, int sche, int *bands_count) {
    
    band -> id = *bands_count;
    *bands_count++;
    band -> sche_type = sche;
    band -> left_pkgs_queue = malloc(INITIAL_queue_SIZE*sizeof(band_t));
    band -> right_pkgs_queue = malloc(INITIAL_queue_SIZE*sizeof(band_t));
    band -> left_pkgs_count = 0;
    band -> right_pkgs_count = 0;
    band -> on = false;
}

int get_dir() {
    //TODO: not implemented yet
    return 0;
}

int update_file(int pkg_id, int pos, int pkg_type) {
    
    //TODO: not implemented yet

    return 0;
}