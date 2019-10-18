/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      Implementation of lpthread library
 * ***********************************************************/

#include <lpthread.h>

int lpthread_create(int (*start_routine) (void *), char *arg) {
    int lpthread_id = 0;

    // Allocate stack for child task.
    const int STACK_SIZE = 65536;
    char* stack = malloc(STACK_SIZE);
    
    if (!stack) {
        perror("malloc");
        exit(1);
    }

    //flags needed to create a thread with clone
    int flags = SIGCHLD | CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SYSVSEM 
        | CLONE_SIGHAND | CLONE_PARENT_SETTID;
         //| CLONE_SETTLS | CLONE_THREAD | CLONE_CHILD_CLEARTID

    lpthread_id = clone(start_routine, stack + STACK_SIZE, flags, arg);
    if ( lpthread_id == -1 ) {
        perror("clone");
        exit(1);
    }

    return lpthread_id;
}

int lpthread_end() {
    _exit(0);
}

int lpthread_yield() {
    return sched_yield();
}

int lpthread_join(int lpthread_id) {
    
    siginfo_t infop;    
    int status;

    if (waitpid(lpthread_id, &status, 0) == -1) {
        perror("wait");
        exit(1);
    }
    
    return status;
}

int lpthread_detach() {
    //TODO: implement method
}
