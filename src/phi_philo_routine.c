/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/03/06 13:38:43 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*phi_philo_routine(void *void_philo)
{
	int		i;
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)void_philo;
	data = philo->data;
	// if (philo->id % 2 == 0)
	// 	usleep(1 * 1000);
	i = 0;
	while (!phi_is_philo_full(philo) && !phi_is_philo_dead(philo))
	{
		pthread_mutex_lock(philo->left_fork);
		phi_print(data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		phi_print(data, philo->id, "has taken a fork");
		phi_print(data, philo->id, "is eating");
		usleep(data->eat_time * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		philo->last_meal = phi_absolute_time();
		philo->meals++;
		if (phi_is_philo_full(philo))
			return (NULL);
		phi_print(data, philo->id, "is sleeping");
		usleep(data->sleep_time * 1000);
		phi_print(data, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}
