/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:22:37 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/16 17:12:21 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	*hello(void *arg)
{
	(void) arg;
    printf("Hello from thread\n");
	sleep(120);
	printf("Dead\n");
	return (NULL);
}

int main(void)
{
    pthread_t	thread1;
	pthread_t	thread2;

	pthread_create(&thread1, NULL, &hello, NULL);
	pthread_create(&thread2, NULL, &hello, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return (0);
}