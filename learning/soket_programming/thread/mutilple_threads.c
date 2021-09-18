#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Let us create a global variable to change it in threads
int g = 0;
// The function to be excecute by all threads
void *myThreadFun (void * vargp) {
    // Store the value argument passed to this thread
    int *myID = (int *)vargp;
    // create a static variable to observe its changes
    static int s = 0;
    ++s; ++g;
    printf ("Thread ID: %d, Static: %d, Global: %d\n", *myID, ++s, ++g);
}

int main () {
    int i;
    pthread_t tid;
    for (i = 0; i < 3; ++i) 
        pthread_create (&tid, NULL, myThreadFun, (void*)&tid);
    pthread_exit(NULL);
    return 0;
}