#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define THINKING 1
#define EATING 2
#define SLEEPING 3


typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
}					t_philo;

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
    {
        // Thinking
        printf("Philo %d is thinking\n", philo->id);
        sleep(1);
        
        // Try to grab forks
        printf("Philo %d is trying to grab forks\n", philo->id);
        
        // Prevent deadlock by having odd philosophers grab right fork first
        if (philo->id % 2 == 0)
        {
            pthread_mutex_lock(philo->left_f);
            printf("Philo %d grabbed left fork\n", philo->id);
            pthread_mutex_lock(philo->right_f);
            printf("Philo %d grabbed right fork\n", philo->id);
        }
        else
        {
            pthread_mutex_lock(philo->right_f);
            printf("Philo %d grabbed right fork\n", philo->id);
            pthread_mutex_lock(philo->left_f);
            printf("Philo %d grabbed left fork\n", philo->id);
        }
        
        // Eating
        printf("Philo %d is eating\n", philo->id);
        sleep(2);
        
        // Put down forks
        pthread_mutex_unlock(philo->left_f);
        pthread_mutex_unlock(philo->right_f);
        printf("Philo %d put down forks\n", philo->id);
        
        // Sleeping
        printf("Philo %d is sleeping\n", philo->id);
        sleep(1);
    }
	return (NULL);
}

int	main(void)
{
	pthread_mutex_t	lock[3];
	t_philo			philo[3];
	pthread_t		thread0;
	pthread_t		thread1;
	pthread_t		thread2;

	pthread_mutex_init(&lock[0], NULL);
	pthread_mutex_init(&lock[1], NULL);
	pthread_mutex_init(&lock[2], NULL);
	philo[0].id = 0;
	philo[1].id = 1;
	philo[2].id = 2;
	philo[0].left_f = &lock[0];
	philo[1].left_f = &lock[1];
	philo[2].left_f = &lock[2];
	philo[0].right_f = &lock[(0 + 2) % 3];
	philo[1].right_f = &lock[(1 + 2) % 3];
	philo[2].right_f = &lock[(2 + 2) % 3];
	pthread_create(&thread0, NULL, philo_routine, &philo[0]);
	pthread_create(&thread1, NULL, philo_routine, &philo[1]);
	pthread_create(&thread2, NULL, philo_routine, &philo[2]);
	pthread_join(thread0, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_mutex_destroy(&lock[0]);
	pthread_mutex_destroy(&lock[1]);
	pthread_mutex_destroy(&lock[2]);
	return (0);
}