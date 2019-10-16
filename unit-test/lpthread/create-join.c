/********************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      Test for the methods lpthread_create and lpthread_join
 *      The test consist of the modification of the buf shared 
 *      variable. The parent send a message in buf then the child
 *      print it, modify buf again with a new message, finally 
 *      the parent have to print the message recive from his child
 * *****************************************************************/

#include <lpthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*************************************************************
 * Method to run on the new thread
 * ***********************************************************/
static int child_func(void* arg) {

  char* buf = (char*)arg;
  printf("Child sees buf = \"%s\"\n", buf);
  strcpy(buf, "hello from child1");
  return 0;
}

int main(int argc, char** argv) {

  char *buf  = (char*) malloc (100*sizeof(char));
  strcpy(buf, "hello from parent");
  
  int lpthread_id = lpthread_create(child_func,  buf);
  int status = lpthread_join(lpthread_id);

  printf("Child exited with status %d. buf = \"%s\"\n", status, buf);
  return 0;
}
