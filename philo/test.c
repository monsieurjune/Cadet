# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>

void *state = (void *)0x1;

void	*first(void *arg)
{
	int	i = 0;
	pthread_mutex_t lock;

	(void)arg;
	pthread_mutex_init(&lock, NULL);
	while (i < 100)
	{
		pthread_mutex_lock(&lock);
		if (state == NULL)
			return (NULL);
		printf("My time : \033[0;32m%d\033[0m\n", i);
		pthread_mutex_unlock(&lock);
		i++;
	}
	pthread_mutex_destroy(&lock);
	return (NULL);
}

void	*second(void *arg)
{
	int	i = 0;
	pthread_mutex_t lock;

	(void)arg;
	pthread_mutex_init(&lock, NULL);
	while (i < 5)
	{	
		printf("Your time : \033[0;31m%d\033[0m\n", i);
		i++;
	}
	pthread_mutex_lock(&lock);
	state = NULL;
	pthread_mutex_unlock(&lock);
	
	pthread_mutex_lock(&lock);
	printf("Your time : \033[0;31m%d\033[0m\n", i);
	pthread_mutex_unlock(&lock);
	pthread_mutex_destroy(&lock);
	return (NULL);
}

// int	i = 0;

// void	*count(void *arg)
// {
// 	pthread_mutex_t lock;

// 	pthread_mutex_init(&lock, NULL);
// 	while (i < 200)
// 	{
// 		pthread_mutex_lock(&lock);
// 		i++;
// 		pthread_mutex_unlock(&lock);
// 	}
// 	pthread_mutex_destroy(&lock);
// 	return (NULL);
// }

int main()
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, NULL, first, NULL);
	pthread_create(&t2, NULL, second, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("I : %p\n", state);
	return (0);
}