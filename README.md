# interviewpreparation

---------------------------------------------------
# Pthreads in C Programming #
Threads are the mechanism to execute tasks concurrently. A single process can have a multiple threads
and each threads share the same data and same process memory for execution like head segment, uninitialized data and
initialized data.
* It is difficult to share information between processes. Since the parent and
child don’t share memory (other than the read-only text segment), we must use
some form of interprocess communication in order to exchange information
between processes.
* Process creation with fork() is relatively expensive, the need to duplicate various process
attributes such as page tables and file descriptor tables means that a fork() call is
still time-consuming

### Threads address both of these problems:
*   Sharing information between threads is easy and fast. It is just a matter of copying
    data into shared (global or heap) variables. However, in order to avoid the
    problems that can occur when multiple threads try to update the same information, 
    we must employ the synchronization techniques described.
*   Thread creation is faster than process creation—typically, ten times faster or better. 
    Thread creation is faster because many of the attributes that must be duplicated in a child created by fork() are instead shared between threads. In particular, copy-on-write duplication of pages of memory is not required, nor is duplication of page tables.

### pthread Data Types
| Data Types | Description |
-------------|-------------
pthread_t    | Thread Identification
pthread_mutex_t| Thread Mutex
pthread_mutex_attr| Thread Attributes
pthread_condt | phtread condition variable
pthread_attr_t | pthread attributes 

### 1) Pthread Creation
``` c
int pthread_create(pthread_t *threadID,  // Thread ID which going to execute
                    const pthread_attr_t *attr, // Pthread attributes
                    void*(*start)(void*), // Function which going to execute by pthread
                    void* args ); // arguments for the thread functions
```
### 2) Pthread Termination

1) Thread can return a value to main thread
2) Thread can call ``` pthread_exit()``` to terminate
3) Thread can call ``` pthread_cancel()``` to terminate
4) Thread can invoke ``` exit()``` function.

``` c
 include <pthread.h>
 void pthread_exit(void *retval);
```

### 3) Thread ID
Thread IDs are useful within applications for the following reasons:
*   Various Pthreads functions use thread IDs to identify the thread on which they
    are to act. Examples of such functions include 
    ``` c
        pthread_join(), pthread_detach(),
        pthread_cancel()  & pthread_kill()
    ```
*   In some applications, it can be useful to tag dynamic data structures with the
    ID of a particular thread. This can serve to identify the thread that created or
    “owns” a data structure, or can be used by one thread to identify a specific
    thread that should subsequently do something with that data structure.

### 4) Join the Terminated Thread
``` pthread_join() ``` function will wait for the thread to terminate and begin after joing the thread
``` c
    include<pthread.h>
    int pthread_join(pthread_t threadID, void** returnValue);
 ```
Example of Thread Join:
```c
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

static void* ThreadFunction(void* args) {
        char* s = (char*) args;
        printf("%s",s);
        return (void*) strlen(s);
}

int main(int argc, char* argv[]) {
        pthread_t t1;
        void* res;

        int threadStatus=pthread_create(&t1, NULL, ThreadFunction, "Hello My Thread\n");

        if(threadStatus != 0){
                printf("[Error]: Failed to create thread\n");
                exit(-1);
        }

        printf("\n Message from main() function\n");

        threadStatus = pthread_join(t1, &res);

        if(threadStatus != 0) {
                printf("[Error]: Failed to pthread_join()\n");
                exit(-1);
        }

        printf("\n Thread Returned %ld",(long)res);

        exit(0);
}
```

### 5) Pthread Detach

If the therad execution not required any return value, we can make that thread as detached by calling the ``` pthread_detach()```
Once the thread is detached, we can not re-join the thread to get result from the thread execution.
``` c
#include<pthread>
int pthread_detach(pthread_t& id);
```
### 6) Pthread Attributes
Attributes are a way to specify behavior that is different from the default. When a thread is created with pthread_create() or
when a synchronization variable is initialized, an attribute object can be specified. Note: however that the default atributes 
are usually sufficient for most applications.

* **Impottant Note**: Attributes are specified only at thread creation time; they cannot be altered while the thread is being used.
```c
#include <pthread.h>

pthread_attr_t tattr;
pthread_t tid;
void *start_routine;
void arg
int ret;

/* initialized with default attributes */
ret = pthread_attr_init(&tattr);

/* call an appropriate functions to alter a default value */
ret = pthread_attr_*(&tattr,SOME_ATRIBUTE_VALUE_PARAMETER);

/* create the thread */
ret = pthread_create(&tid, &tattr, start_routine, arg);

```

## Thread Synchronization ##

### 1) Protecting the Shared resource in Theraded Application
Usaually threads share the global inforamtion for there exection. If each threads share information and try to modify the informaion may cause inconsistency in data
To overcome from the data inconsistency we need to use the ``` pthread_mutex_t ```.
We can initialize the mutex statically and dynamically. Below examples will indicate both ways of using the mutex locks.

```c
static int glob = 0;

/* Static Mutex Thread created*/
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void* threadFunction(void* args) {
        int loops = *((int*)args);
        int loc, j;

        pthread_mutex_lock(&mutex);
        for(j=0; j<loops; j++) {
                loc=glob;
                loc++;
                glob=loc;
        }
        pthread_mutex_unlock(&mutex);

        return NULL;
}
```
### 2) Mutex Deadlocks
Sometimes, a thread needs to simultaneously access two or more different shared
resources, each of which is governed by a separate mutex. When more than one
thread is locking the same set of mutexes, deadlock situations can arise. 

| Thread A | Thread B|
|----------|---------|
| pthread_mutex_lock(m1)| pthread_mutex_lock(m2)|
| pthread_mutex_lock(m2)| pthread_mutex_lock(m1) |

