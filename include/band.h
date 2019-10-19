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

/***********************************
 * Direction to move packages
 * *********************************/
#define LEFT_TO_RIGHT 0
#define RIGHT_TO_LEFT 1

/***********************************
 * Scheduling types
 * *********************************/
#define ROUND_ROBIN_SCHE 0
#define SJF_SCHE         1  //shortest job first
#define FIFO_SCHE        2
#define RT_SCHE          3   //Real time

#define INITIAL_queue_SIZE 20

typedef struct
{
    int id;
    int sche_type;
    //TODO: if is necesary a method to make the 
    //queue larger
    queue_t *left_pkgs_queue;
    queue_t *right_pkgs_queue;
    //# of pkgs in ready queue
    int left_pkgs_count;
    int right_pkgs_count;
    bool on;
} band_t;

/*************************************************************
 * Description:
 *      move a package from one site to another
 * Parameters:
 *      pkg -> pkg to mov
 *      dir -> Direction to move the pkg
 * return:
 * ***********************************************************/
void mov_package(package_t *pkg, int dir);

/*************************************************************
 * Description:
 *      Create new packages
 * Parameters:
 * return:
 *      Ptr to the array of new packages
 * ***********************************************************/
package_t* generate_pkgs(int *pkg_counter);

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
 *      Close the band's thread
 * Parameters:
 *      Band to work
 * return:
 *      
 * ***********************************************************/
void turn_of_band(band_t *pkg);

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
 *      choose direction to move the pkg
 * Parameters:
 *      
 * return:
 *      0 -> LEFT_TO_RIGHT
 *      1 -> RIGHT_TO_LEFT
 * ***********************************************************/
int get_dir();

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
int update_file(int pkg_id, int pos, int pkg_type);

#endif