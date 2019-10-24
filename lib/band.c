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
    
    int pos = (dir == LEFT_TO_RIGHT) ? 1 : 8;
    
    printf("moving package %d\n", pkg->id);
    update_file("Bandas/Banda0", pos, pkg->type);
    
    int time = compute_time(pkg->weight);
    time /= 8;
    for (int i = 0; i < 7; i++) {
        sleep(time);
        if (dir == LEFT_TO_RIGHT)
            pos++;
        else
            pos--;
        
        update_file("Bandas/Banda0", pos, pkg->type);
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
    package_t *queue_selected;
    //next pkg to move
    package_t *next_pkg;
    int next_pkg_index;
    int pkg_id_counter = 0;
    
    int direction;// flux for the packages
    int side; //wich side of the band will the packages go when created
    band->on = true;
    printf("Band %d working!\n", band->id);

    while(band->on == true) {

        generate_pkgs(&pkg_id_counter, &band -> left_pkgs_count, 
                        band -> left_pkgs_queue, &band -> left_pkgs_size);
        generate_pkgs(&pkg_id_counter, &band -> right_pkgs_count, 
                        band -> right_pkgs_queue, &band -> right_pkgs_size);
        
        srand(time(0)); //init random
        direction = rand() % 2;

        if (direction == LEFT_TO_RIGHT) 
            next_pkg = get_next_item(band->left_pkgs_queue, &band->left_pkgs_count, band->sche_type);
        else 
            next_pkg = get_next_item(band->right_pkgs_queue, &band->right_pkgs_count, band->sche_type);

        if (direction == LEFT_TO_RIGHT) band->left_pkgs_count--;
        else band->right_pkgs_count--;
    
        mov_package(next_pkg, direction);
    }

    return 0;
}

void generate_pkgs(int *pkg_id_counter, int *pkgs_count, 
                         package_t* pkgs_queue, int* pkgs_size) {
    printf("Hi/n");
    srand(time(0)); //init random
    int qntty = get_qntty();
    
    if (qntty == 0) {
        if (*pkgs_count != 0)
            return; 
        else
            qntty++;
    }

    printf("%d pkgs generated\n", qntty);

    if (qntty > *pkgs_size - *pkgs_count) {
        pkgs_queue = realloc(pkgs_queue, *pkgs_size + INITIAL_QUEUE_SIZE);
        *pkgs_size += INITIAL_QUEUE_SIZE;
    }
        
    for (int i = *pkgs_count; i < *pkgs_count + qntty; i++)
        pkg_init(&pkgs_queue[i], pkg_id_counter++);

    *pkgs_count += qntty;
}

void turn_off_band(band_t *band) { band->on = false; }

void band_init(band_t *band, int sche, int *bands_count) {
    
    band -> id = *bands_count;
    *bands_count++;
    band -> sche_type = sche;
    band -> left_pkgs_queue = malloc(INITIAL_QUEUE_SIZE*sizeof(package_t));
    band -> right_pkgs_queue = malloc(INITIAL_QUEUE_SIZE*sizeof(package_t));
    band -> left_pkgs_count = 0;
    band -> right_pkgs_count = 0;
    band -> on = false;
    band -> dir = 0;
    band -> left_pkgs_size = INITIAL_QUEUE_SIZE;
    band -> right_pkgs_size = INITIAL_QUEUE_SIZE;
    int flux_from_file = 0; //Default: sign
    //TODO: Agarrar tipo de flujo del archivo de configuracion
    // flux_from_file = functionToGetDataFromFile("flux"); // argument to indicate wich parameter to get. In this case, the flux type  
    band -> flux_type = flux_from_file;
    // printf("on init: Band sche is %d\n", band->sche_type);
}

int update_file(char *file, int pos, int pkg_type) {
    
    FILE * fp = fopen (file, "w");
    if (fp == NULL) {
        printf("error opening file...\n");
        return -1;
    }
    printf("%d,%d\n", pkg_type, pos);
    fprintf (fp, "%d,%d\n", pkg_type, pos);
    fclose (fp);
    return 0;
}