/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      FIle Read library implementation
 * Based on https://www.zentut.com/c-tutorial/c-read-text-file/
 * ***********************************************************/
#include <stdio.h>
#include <file_read.h>
 
#define MAXCHAR 1000

 int read_file(const char *filename, parameters_t *input_parameters){
    FILE *fp;
    char str[MAXCHAR];
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        printf("%s", str);
    fclose(fp);
    return 0;
}