/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_is_philo_full.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/03/06 13:38:43 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	phi_is_philo_full(t_philo *philo)
{
	t_data	*data;
	int		is_philo;

	data = philo->data;
	pthread_mutex_lock(&(philo->meals_mutex));
	is_philo = (data->meals_max != -1 && philo->meals >= data->meals_max);
	pthread_mutex_unlock(&(philo->meals_mutex));
	return (is_philo);
}

int	phi_is_every_philo_full(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		if (!phi_is_philo_full(&(data->philos[i])))
			return (0);
		i++;
	}
	return (1);
}
