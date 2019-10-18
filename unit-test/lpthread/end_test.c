/********************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      Test the lpthread_end() Method
 * *****************************************************************/

#include <lpthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*************************************************************
 * Method to run on the new thread
 * ***********************************************************/
static int child_func(void* arg) {

  printf("Inside the thread\n");
  lpthread_end();
  printf("This message is never shown\n");
  return 0;
}

int main(int argc, char** argv) {

  int lpthread_id = lpthread_create(child_func, NULL);
  int status = lpthread_join(lpthread_id);

  printf("\nExiting...\n");
  return 0;
}
