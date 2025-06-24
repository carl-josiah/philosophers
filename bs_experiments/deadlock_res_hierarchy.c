#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_data
{
    int             philo_id;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *first_fork;
    pthread_mutex_t *second_fork;
}                   t_data;

void	*resource_hierarchy(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	for (int i; i < 5; i++)
	{

		if (data->philo_id == 0)
		{
			printf("Philo 0 is trying to eat\n");
			pthread_mutex_lock(data->first_fork);
			printf("Philo 0 grabs first fork\n");
			pthread_mutex_lock(data->second_fork);
			printf("Philo 0 grabs second fork\n");
			printf("Philo 0 is eating\n");
			sleep(3);
			pthread_mutex_unlock(data->second_fork);
			pthread_mutex_unlock(data->first_fork);
			printf("Philo 0 is thinking\n");
		}
		if (data->philo_id == 1)
		{
			printf("Philo 1 is trying to eat\n");
			pthread_mutex_lock(data->first_fork);
			printf("Philo 1 grabs first fork\n");
			pthread_mutex_lock(data->second_fork);
			printf("Philo 1 grabs second fork\n");
			printf("Philo 1 is eating\n");
			sleep(3);
			pthread_mutex_unlock(data->second_fork);
			pthread_mutex_unlock(data->first_fork);
			printf("Philo 1 is thinking\n");
		}
		if (data->philo_id == 2)
		{
			printf("Philo 2 is trying to eat\n");
			pthread_mutex_lock(data->first_fork);
			printf("Philo 2 grabs first fork\n");
			pthread_mutex_lock(data->second_fork);
			printf("Philo 2 grabs second fork\n");
			printf("Philo 2 is eating\n");
			sleep(3);
			pthread_mutex_unlock(data->second_fork);
			pthread_mutex_unlock(data->first_fork);
			printf("Philo 2 is thinking\n");
		}
	}
	return (NULL);
}

int main(void)
{
    t_data          philo_data[3];
    pthread_t       philo[3];
    pthread_mutex_t fork[3];

    for (int i = 0; i < 3; i++)
        philo_data[i].philo_id = i;
    for (int i = 0; i < 3; i++)
    	pthread_mutex_init(&fork[i], NULL);
	philo_data[0].left_fork = &fork[0];
	philo_data[0].right_fork = &fork[1];
	philo_data[1].left_fork = &fork[2];
	philo_data[1].right_fork = &fork[0];
	philo_data[2].left_fork = &fork[1];
	philo_data[2].right_fork = &fork[2];
	for (int i = 0; i < 3; i++)
	{
		if (philo_data[i].left_fork < philo_data[i].right_fork)
		{
			philo_data[i].first_fork = philo_data[i].left_fork;
			philo_data[i].second_fork = philo_data[i].right_fork;
		}
		else
		{
			philo_data[i].first_fork = philo_data[i].right_fork;
			philo_data[i].second_fork = philo_data[i].left_fork;
		}
	}
	for (int i = 0; i < 3; i++)
		pthread_create(&philo[i], NULL, resource_hierarchy, &philo_data[i]);
	for (int i = 0; i < 3; i++)
		pthread_join(philo[i], NULL);
	for (int i = 0; i < 3; i++)
		pthread_mutex_destroy(&fork[i]);
    return (0);
}
