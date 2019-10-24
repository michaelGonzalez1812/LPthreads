/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      Library with the functionality to read from config
 *      file
 * ***********************************************************/

// #ifndef FILE_READ_H
// #define FILE_READ_H

#include <stdio.h>


typedef struct
{
    int flux_control;   // 0: letrero, 1:W, 2:aleatorio
    int strenght;       // fuerza de banda
    int lenght;         // El largo de la banda
    int probability;    // Distribución media de generación de paquetes
    int sing_time;      // El tiempo que el letrero cambie
    int w;              // El parámetro W
    int radioactive;    // Porcentaje de paquetes radioactivos
    int urgent;         // Porcentaje de paquetes urgentes
} parameters_t;

#define MAXCHAR 1000

/*************************************************************
 * Description:
 *      fills the struct of parameters from a file with .txt extension
 * Parameters:
 *      filename -> file to read from
 * return:
 *      input_parameters -> struct with parameters from file
 * ***********************************************************/
int read_file(const char *filename, parameters_t *input_parameters);
