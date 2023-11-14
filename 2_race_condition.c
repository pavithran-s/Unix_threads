#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/**
 * - In threads resorces are shared. So val is shared between thread1 and thread2.
 * - Basic increament operation has following three steps
 *      1. read value from memory to CPU register
 *      2. increment by 1
 *      3. write value from CPU register to memory
 * - Two threads are running async we may loose the increatment value at the end.
 * - This undesirable situation is called as race condition
*/
int val = 0;

void* routine()
{
    for (int i = 0; i < 100000; ++i)
    {
        val++;
    }
}

int main()
{   
    pthread_t thread1, thread2;

    if (pthread_create(&thread1, NULL, &routine, NULL) != 0)
    {
        printf("Error in creating thread!");
        return 1;
    }

    if (pthread_create(&thread2, NULL, &routine, NULL) != 0)
    {
        printf("Error in creating thread!");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    printf("Val: %d\n", val);

    return 0;
}

// Source: https://www.youtube.com/watch?v=FY9livorrJI&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=3