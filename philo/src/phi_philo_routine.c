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

static void	phi_philo_eat_sleep_think(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(philo->left_fork);
	phi_print(data, philo->id, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	phi_print(data, philo->id, "has taken a fork");
	phi_print(data, philo->id, "is eating");
	phi_sleep(data, data->eat_time);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->last_meal = phi_absolute_time();
	philo->meals++;
	if (phi_is_philo_full(philo) || data->one_died)
		return ;
	phi_print(data, philo->id, "is sleeping");
	phi_sleep(data, data->sleep_time);
	phi_print(data, philo->id, "is thinking");
}

void	*phi_philo_routine(void *void_philo)
{
	int		i;
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)void_philo;
	data = philo->data;
	if (data->philo_nb == 1)
	{
		phi_print(data, philo->id, "has taken a fork");
		phi_sleep(data, data->die_time);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(data->eat_time * 100);
	i = 0;
	while (!phi_is_philo_full(philo) && !data->one_died)
	{
		phi_philo_eat_sleep_think(philo);
		i++;
	}
	return (NULL);
}
