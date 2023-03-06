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

	data->forks = malloc(data->philo_nb * sizeof(pthread_mutex_t));
	if (!data->forks)
		phi_error_exit(data, "malloc failed");
	i = 0;
	while (i < data->philo_nb)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			phi_error_exit(data, "pthread_mutex_init failed");
		i++;
	}
}

static void	phi_create_philos(t_data *data)
{
	int	i;

	data->philos = malloc(data->philo_nb * sizeof(t_philo));
	if (!data->philos)
		phi_error_exit(data, "malloc failed");
	i = 0;
	while (i < data->philo_nb)
	{
		data->philos[i].id = i + 1;
		data->philos[i].left_fork = data->forks + i;
		data->philos[i].right_fork = data->forks + (i + 1) % data->philo_nb;
		i++;
	}
}

void	phi_create_data(t_data *data)
{
	phi_create_forks(data);
	phi_create_philos(data);
}
