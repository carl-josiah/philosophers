#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_data
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_data;

void	*deadlock(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (data->id == 0)
	{
		printf("Philosopher 0 picks up his right fork\n");
		fflush(stdout);
		pthread_mutex_lock(data->right_fork);
		sleep(1);
		printf("Philosopher 0 tries to pick up his right fork\n");
		fflush(stdout);
		pthread_mutex_lock(data->left_fork);
	}
	if (data->id == 1)
	{
		printf("Philosopher 1 picks up his left fork\n");
		fflush(stdout);
		pthread_mutex_lock(data->left_fork);
		sleep(1);
		printf("Philosopher 0 picks up his right fork\n");
		fflush(stdout);
		pthread_mutex_lock(data->right_fork);
	}
	return (NULL);
}

int	main(void)
{
	t_data			data[2];
	pthread_t		philo[2];
	pthread_mutex_t	fork[2];

	pthread_mutex_init(&fork[0], NULL);
	pthread_mutex_init(&fork[1], NULL);
	data[0].id = 0;
	data[0].left_fork = &fork[0];
	data[0].right_fork = &fork[1];
	data[1].id = 1;
	data[1].left_fork = &fork[1];
	data[1].right_fork = &fork[0];
	pthread_create(&philo[0], NULL, deadlock, &data[0]);
	pthread_create(&philo[1], NULL, deadlock, &data[1]);
	pthread_join(philo[0], NULL);
	pthread_join(philo[1], NULL);
	return (0);
}
