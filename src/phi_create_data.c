/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_create_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/01/30 14:22:25 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	phi_create_forks(t_data *data)
{
	int	i;

	data->forks = calloc(data->philo_nb, sizeof(pthread_mutex_t *));
	if (!data->forks)
		phi_error_exit(data);

	i = 0;
	while (i < data->philo_nb)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			phi_error_exit(data);
		i++;
	}
}

static void	phi_create_philos(t_data *data)
{
	int	i;

	data->philos = calloc(data->philo_nb, sizeof(t_philo));
	if (!data->philos)
		phi_error_exit(data);

	i = 0;
	while (i < data->philo_nb)
	{
		data->philos[i].id = i + 1;
		data->philos[i].left_fork = 0;
		i++;
	}
}

void	phi_create_data(t_data *data)
{
	phi_create_forks(data);
	phi_create_philos(data);
}
