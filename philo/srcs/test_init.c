#include "../incs/philo.h"

void	test_init(t_philo *philo, t_info *info)
{
    int i;

    printf("=== t_info struct ===\n");
    printf("philo_count:      %d\n", info->philo_count);
    printf("death_time:       %llu\n", info->death_time);
    printf("eat_time:         %llu\n", info->eat_time);
    printf("sleep_time:       %llu\n", info->sleep_time);
    printf("required_meals:   %d\n", info->required_meals);
    printf("philo_died:       %d\n", info->philo_died);
    printf("meal_limit_reached:   %d\n", info->meal_limit_reached);
    printf("fork_init_flag:  %d\n", info->fork_init_flag);
    printf("start_time:       %llu\n", info->start_time);
    printf("philo pointer:    %p\n", (void *)info->philo);
    printf("forks array:      %p\n", (void *)info->forks);
    printf("fork_locks array: %p\n", (void *)info->fork_locks);
    printf("print_lock addr:  %p\n", (void *)&info->print_lock);

    printf("\n=== Fork IDs ===\n");
    for (i = 0; i < info->philo_count; i++)
        printf("forks[%d]: %d\n", i, info->forks[i]);

    printf("\n=== Philosopher structs ===\n");
    for (i = 0; i < info->philo_count; i++)
    {
        printf("\nPhilosopher %d at %p:\n", i + 1, (void *)&philo[i]);
        printf("  id:             %d\n", philo[i].id);
        printf("  meal_count:     %d\n", philo[i].meal_count);
        printf("  last_meal_time: %llu\n", philo[i].last_meal_time);
        printf("  left_fork:      %p (value: %d)\n", (void *)philo[i].left_fork, *philo[i].left_fork);
        printf("  right_fork:     %p (value: %d)\n", (void *)philo[i].right_fork, *philo[i].right_fork);
        printf("  lock_left:      %p\n", (void *)philo[i].lock_left);
        printf("  lock_right:     %p\n", (void *)philo[i].lock_right);
        printf("  thread addr:    %p\n", (void *)&philo[i].thread);
        printf("  info pointer:   %p\n", (void *)philo[i].info);
    }
}