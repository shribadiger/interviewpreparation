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

