/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      This library implements basics methods to creation
 *      and manipulation of linux kernel threads
 * ***********************************************************/

/*************************************************************
 * Description:
 *      Create new thread
 * Parameters:
 *      start_routine -> method wich will run on the thread
 *      arg -> Arguments to the start_routine
 * return:
 *      new thread id
 * ***********************************************************/
int lpthread_create(int (*start_routine) (void *), char *arg);

int lpthread_end();

int lptrhread_yield();

/*************************************************************
 * Description:
 *      Wait for the exit of a thread
 * Parameters:
 *      lpthread_id -> ID of the thread to wait
 * return:
 *      Status of the exiting thread
 * ***********************************************************/
int lpthread_join(int lpthread_id);

int lpthread_detach();

int lmutex_init();

int lmutex_destroy();

int lmutex_unlock();

int lmutex_trylock();