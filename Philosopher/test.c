void* increment_counter(void* arg)
{
    t_counter *st = arg;
	pthread_mutex_lock(&st->mutex);
	while (st->counter != 5)
	{
		st->counter++;
		// printf("%d\n", (int)st->counter);
	}
	
	pthread_mutex_unlock(&st->mutex);
	
	return NULL;
}

int main()
{
    t_counter *st = NULL;
    pthread_mutex_init(&st->mutex, NULL);

    pthread_t thread1;//, thread2;
    pthread_create(&thread1, NULL, increment_counter, &st);
    //   printf("Main: Created first thread [%ld]\n", thread1);
    // pthread_create(&thread2, NULL, increment_counter, &st);
    //   printf("Main: Created first thread [%ld]\n", thread2);

    pthread_join(thread1, NULL);
    // pthread_join(thread2, NULL);

    pthread_mutex_destroy(&st->mutex);
    usleep(2000);
    printf("%d\n", (int)st->counter);

    return 0;
}


// +++++++++++++++++++++++++++++




// ++++++++++++++++++++++++++++++++++++++++

// void ft_my_sleep(int ms)
// {
//     struct timeval  now;
//     struct timeval  start;
//     gettimeofday(&now, NULL);
//     gettimeofday(&start, NULL);
//     while ((((now.tv_sec - start.tv_sec) * 1000) + ((now.tv_usec - start.tv_usec) / 1000)) < ms)
//     {
//         usleep(100);
//         gettimeofday(&now, NULL);
//     }
// }


// long    get_time(void)
// {
//     struct timeval  tp;
//     long            milliseconds;

//     gettimeofday(&tp, NULL);
//     milliseconds = tp.tv_sec * 1000;
//     milliseconds += tp.tv_usec / 1000;
//     return (milliseconds);
// }

// int main(void)
// {
//     long start_time;
		
//     start_time = get_time();

//     while (1)
//     {
//         printf("%ld\n", get_time() - start_time);
//         // usleep(200000);
//         ft_my_sleep(500);
//     }
// }

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define NUM_FORKS 5

pthread_mutex_t forks[NUM_FORKS];
pthread_t philosophers[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int id = *(int *)arg;
    int left_fork = id;
    int right_fork = (id + 1) % NUM_FORKS;

    while (1) {
        printf("Philosopher %d is thinking...\n", id);

        // Pick up left fork
        pthread_mutex_lock(&forks[left_fork]);
        printf("Philosopher %d picks up left fork %d\n", id, left_fork);

        // Pick up right fork
        pthread_mutex_lock(&forks[right_fork]);
        printf("Philosopher %d picks up right fork %d\n", id, right_fork);

        printf("Philosopher %d is eating...\n", id);

        // Put down right fork
        pthread_mutex_unlock(&forks[right_fork]);
        printf("Philosopher %d puts down right fork %d\n", id, right_fork);

        // Put down left fork
        pthread_mutex_unlock(&forks[left_fork]);
        printf("Philosopher %d puts down left fork %d\n", id, left_fork);

        // Wait a bit before thinking again
        usleep(100000);
    }
}

int main() {
    int i;
    int ids[NUM_PHILOSOPHERS];

    // Initialize mutexes for forks
    for (i = 0; i < NUM_FORKS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create threads for each philosopher
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Wait for threads to finish (this should never happen)
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes for forks
    for (i = 0; i < NUM_FORKS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
