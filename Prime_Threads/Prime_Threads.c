#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

/*Range for the functions to calculate prime.*/
#define RANGE 10000

/*Creating a global mutex lock.*/
pthread_mutex_t threadLock = PTHREAD_MUTEX_INITIALIZER;

/*Global counters*/
int primeCounter = 0;
int x = 2;

/*Function prototypes.*/
void *primeCounter1();
void *primeCounter2();

int main()
{
    pthread_t T1, T2;

    /*Create the threads.*/
    int id1 = pthread_create(&T1, NULL, primeCounter1, NULL);
    int id2 = pthread_create(&T2, NULL, primeCounter2, NULL);

    /*Check for thread creation errors.*/
    if (id1)
    {
        printf("Thread creation error...\n");
        exit(EXIT_FAILURE);
    }

    if (id2)
    {
        printf("Thread creation error...\n");
        exit(EXIT_FAILURE);
    }

    /*Join the threads.*/
    pthread_join(T1, NULL);
    pthread_join(T2, NULL);    

    printf("The number of primes is: %d\n", primeCounter);
}

/*Function 1.*/
void *primeCounter1()
{
    int count;

    /*Initial assignment, locking the value.*/
    pthread_mutex_lock(&threadLock);
    int temp = x;
    x++;
    pthread_mutex_unlock(&threadLock);

    /*This value will be used as a boolean.*/
    char isPrime = 1;

    /*While the temp (x) is less than the constant RANGE.*/
    while (temp < RANGE)
    {
        /*For every number not 1, and less than temp...*/
        for (count = 2; count < temp; count++)
        {
            /*If the mod equals 0. The number is not prime.*/
            if (!(temp % count))
            {
                /*Set the boolean, and break out of the loop.*/
                isPrime = 0;
                break;
            }            
        }

        /*If is prime... increment the counter.*/
        if (isPrime == 1)
        {
            /*Lock the thread.*/
            pthread_mutex_lock(&threadLock);
            primeCounter++;
            pthread_mutex_unlock(&threadLock);
        }
        /*Else, the number is not prime.*/
        else
        {
            /*Reset the boolean.*/
            isPrime = 1;
        }

        /*Grab the next value by locking, then assigning.*/
        pthread_mutex_lock(&threadLock);
        temp = x;
        x++;
        pthread_mutex_unlock(&threadLock);     
    }
}

/*Function 2.*/
void *primeCounter2()
{
    int count;

    /*Initial assignment, locking the value.*/
    pthread_mutex_lock(&threadLock);
    int temp = x;
    x++;
    pthread_mutex_unlock(&threadLock);

    /*This value will be used as a boolean.*/
    char isPrime = 1;

    /*While the temp (x) is less than the constant RANGE.*/
    while (temp < RANGE)
    {
        /*For every number not 1, and less than temp...*/
        for (count = 2; count < temp; count++)
        {
            /*If the mod equals 0. The number is not prime.*/
            if (!(temp % count))
            {
                /*Set the boolean, and break out of the loop.*/
                isPrime = 0;
                break;
            }            
        }

        /*If is prime... increment the counter.*/
        if (isPrime == 1)
        {
            /*Lock the thread.*/
            pthread_mutex_lock(&threadLock);
            primeCounter++;
            pthread_mutex_unlock(&threadLock);
        }
        /*Else, the number is not prime.*/
        else
        {
            /*Reset the boolean.*/
            isPrime = 1;
        }

        /*Grab the next value by locking, then assigning.*/
        pthread_mutex_lock(&threadLock);
        temp = x;
        x++;
        pthread_mutex_unlock(&threadLock);     
    }
}