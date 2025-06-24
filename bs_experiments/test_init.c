#include "../incs/philo.h"

void	test_init(t_sim *info)
{
	for (int i = 0; i < info->args->philo_count; i++)
	{
		printf("philo id: %d\n", info->philos[i].id);
		printf("philo time: %d\n", info->philos[i].time);
		printf("philo state: %d\n", info->philos[i].state);
		printf("philo meal_count: %d\n\n", info->philos[i].meal_count);
		printf("philo left fork: %p\n", info->philos[i].left_fork);
		printf("philo right fork: %p\n\n", info->philos[i].right_fork);
		printf("philo first fork: %p\n", info->philos[i].first_fork);
		printf("philo second fork: %p\n\n", info->philos[i].second_fork);
	}
}
