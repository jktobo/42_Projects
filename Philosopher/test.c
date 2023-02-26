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
