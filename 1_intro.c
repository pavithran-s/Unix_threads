#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/** @brief Function which will run inside thread1 and thread2
 * @return it need to return a pointer
*/
void* routine()
{
    printf("Hello from thread\n");
    sleep(2);
    printf("Bye from thread\n");
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

    return 0;
}

// Run: gcc -g -pthread 1_intro.c && ./a.out
// Source: https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=1
