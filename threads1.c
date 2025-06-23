#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_num
{
	int	count;
}		t_num;

void	*increment_c(void *arg)
{
	int	i;

	i = 0;
	while (i < 400000)
	{
		(*(int *)arg)++;
		i++;
	}
	return (NULL);
}

void	*increment_b(void *arg)
{
	int			i;
	pthread_t	thread_c;

	i = 0;
	while (i < 200000)
	{
		(*(int *)arg)++;
		i++;
	}
	pthread_create(&thread_c, NULL, increment_c, arg);
	pthread_join(thread_c, NULL);
	i = 0;
	while (i < 200000)
	{
		(*(int *)arg)++;
		i++;
	}
	return (NULL);
}

void	*increment_a(void *arg)
{
	int			i;
	pthread_t	thread_b;

	i = 0;
	while (i < 100000)
	{
		(*(int *)arg)++;
		i++;
	}
	pthread_create(&thread_b, NULL, increment_b, arg);
	pthread_join(thread_b, NULL);
	i = 0;
	while (i < 100000)
	{
		(*(int *)arg)++;
		i++;
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	thread_a;
	t_num		number;

	number.count = 0;
	pthread_create(&thread_a, NULL, increment_a, &number.count);
	pthread_join(thread_a, NULL);
	printf("number.count: %d\n", number.count);
	return (0);
}
