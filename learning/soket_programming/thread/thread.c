#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * func (void * arg) {
    // detach the current thread
    // from the calling pthread
    pthread_detach (pthread_self());
    printf ("Inside the thread\n");
    // exit the current thread
    pthread_exit(NULL);
}

void fun () {
    pthread_t ptid;
    // Creating a new thread
    pthread_create (&ptid, NULL, &func, NULL);
    printf ("This line may be printed" 
        " before thread terminates\n");
    // The following line terminates
    // the thread manually
    // pthread_cancel (ptid)
    if (pthread_equal (ptid, pthread_self()))
        printf ("Threads are equal\n");
    else
        printf ("Threads are not equal\n");
    // Waiting for the created thread to terminates
    pthread_join (ptid, NULL);
    printf ("This line will be printed"
        "after thread ends\n");

    pthread_exit (NULL);
}

int main (int argc, char * argv[]) {
    fun();
    return 0;
}