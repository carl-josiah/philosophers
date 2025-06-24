#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_data
{
	int				count;
	pthread_mutex_t	mutex;
}					t_data;

void	*increment(void *arg)
{
	int			i;
	t_data	*data;

	i = 0;
	data = (t_data *)arg;
	printf("Thread %p starting...\n\n", pthread_self());
	while (i < 1000000)
	{
		if (i % 100000 == 0)
			printf("BEFORE INCREMENT: Thread [%p] is at [%d] and value of count is at [%d]\n", pthread_self(), i, data->count);
		pthread_mutex_lock(&data->mutex);
		data->count++;
		i++;
		pthread_mutex_unlock(&data->mutex);
		if (i % 100000 == 0)
			printf("AFTER INCREMENT: Thread [%p] is at [%d] and value of count is at [%d]\n\n", pthread_self(), i, data->count);
	}
	return (NULL);
}

int	main(void)
{
	t_data		data;
	pthread_t	thread_a;
	pthread_t	thread_b;

	data.count = 0;
	pthread_mutex_init(&data.mutex, NULL);
	pthread_create(&thread_a, NULL, increment, &data);
	pthread_create(&thread_b, NULL, increment, &data);
	pthread_join(thread_a, NULL);
	pthread_join(thread_b, NULL);
	pthread_mutex_destroy(&data.mutex);
	printf("data.count: %d\n", data.count);
	return (0);
}