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
 *      to bands
 * ***********************************************************/

#ifndef BAND_H
#define BAND_H

#include <scheduler.h>
#include <package.h>

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/***********************************
 * Direction to move packages
 * *********************************/
#define LEFT_TO_RIGHT 0
#define RIGHT_TO_LEFT 1

/***********************************
 * Scheduling types
 * *********************************/
#define ROUND_ROBIN_SCHE 0
#define PRIORIRY_SCHE    1
#define SJF_SCHE         2  //shortest job first
#define FIFO_SCHE        3
#define RT_SCHE          4   //Real time

/***********************************
 * Flux type // may not be required
 * *********************************/
// #define SIGN        0   //"letrero" The side of package flux defined by a special time variable that switches at a specific time
// #define W           1   //an amount W of packages are carried before switching the flux side
// #define RANDOM      2   //each time a 50/50 random decides de flux




#define INITIAL_QUEUE_SIZE 200

typedef struct
{
    int id;
    int sche_type;
    //TODO: if is necesary a method to make the 
    //queue larger
    package_t *left_pkgs_queue;
    package_t *right_pkgs_queue;
    
    int left_pkgs_size;
    int right_pkgs_size;
    //# of pkgs in ready queue
    int left_pkgs_count;
    int right_pkgs_count;
    bool on;
    int dir; //direction to move the pkg
    int flux_type;
} band_t;

/*************************************************************
 * Description:
 *      move a package from one side to another
 * Parameters:
 *      pkg -> pkg to mov
 *      dir -> Direction to move the pkg
 * return:
 * ***********************************************************/
void mov_package(package_t *pkg, int dir, int band_id);


/*************************************************************
 * Description:
 *      Main method to the band. It has the infinite loop
 * Parameters:
 *      Band to work
 * return:
 *      -1 -> error
 * ***********************************************************/
int do_in_background(void *arg);

/*************************************************************
 * Description:
 *      Create new packages using a probability distribution for 
 *      how many packages will be created
 *      
 *      If the new quantity pks if greater than space in queue
 *      it creates the same quantity than INITIAL_QUEUE_SIZE more spaces
 * Parameters:
 *      pkg_counter:keeps track of package quantity
 * return:
 *      Ptr to the array of new packages
 *      size of the resulting array
 * ***********************************************************/
void generate_pkgs(int *pkg_id_counter, int *pkgs_count, 
                         package_t* pkgs_queue, int* pkgs_size);

/*************************************************************
 * Description:
 *      Close the band's thread
 * Parameters:
 *      Band to work
 * return:
 *      
 * ***********************************************************/
void turn_off_band(band_t *pkg);

/*************************************************************
 * Description:
 *      Initialize the data to work with the band
 * Parameters:
 *      Band to work
 * return:
 * ***********************************************************/
void band_init(band_t *band, int sche, int *bands_count);

/*************************************************************
 * Description:
 *      update the file with the position of the pkg
 * Parameters:
 *      pkg_id -> Id of the band to know wich file update
 *      pos -> current pkg position [0,7]
 *      pkg_type -> pkg type
 * return:
 *       0 -> success
 *      -1 -> error
 * ***********************************************************/
int update_file(char *file, int pos, int pkg_type);

#endif