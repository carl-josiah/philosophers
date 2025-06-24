#include "incs/philo.h"

int	main(void)
{
	struct timeval	val;
	long long		start_time;
	long long		curr_time;

	gettimeofday(&val, NULL);
	start_time = val.tv_sec * 1000 + val.tv_usec / 1000;
	while (1)
	{
		usleep(1000);
		gettimeofday(&val, NULL);
		curr_time = val.tv_sec * 1000 + val.tv_usec / 1000;
		printf("%lld\n", curr_time - start_time);
	}
	return (0);
}
