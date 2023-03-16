/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/01/30 14:22:25 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	phi_reset_forks(t_data *data)
{
	int	i;

	i = 0;
	while (data->forks && i < data->philo_nb)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
}

void	phi_reset(t_data *data)
{
	pthread_mutex_destroy(&(data->one_died_mutex));
	pthread_mutex_destroy(&(data->print_mutex));
	phi_reset_forks(data);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}
