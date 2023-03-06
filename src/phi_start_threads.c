/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_start_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/03/06 13:38:43 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*phi_philo_routine(void *void_philo)
{
	int		i;
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)void_philo;
	data = philo->data;
	// if (philo->id % 2)
	// 	usleep(15000);
	i = 0;
	while (i < 10)
	{
		pthread_mutex_lock(philo->left_fork);
		printf("%i has taken a fork\n", philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("%i has taken a fork\n", philo->id);
		printf("%i is eating\n", philo->id);
		usleep(data->eat_time * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		printf("%i is sleeping\n", philo->id);
		usleep(data->sleep_time * 1000);
		printf("%i is thinking\n", philo->id);
		i++;
	}
	return (NULL);
}

void	phi_start_threads(t_data *data)
{
	int	i;

	gettimeofday(&(data->time_0), NULL);
	i = 0;
	while (i < data->philo_nb)
	{
		if (pthread_create(&(data->philos[i].thread), NULL, phi_philo_routine, &(data->philos[i])))
			phi_error_exit(data, "pthread_create failed");
		usleep(10000);
		i++;
	}
}