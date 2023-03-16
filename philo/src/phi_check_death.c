/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_check_death_routine.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/03/06 13:38:43 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	phi_wait_for_first_death(t_data *data)
{
	int		i;

	while (!phi_is_every_philo_full(data))
	{
		i = 0;
		while (i < data->philo_nb)
		{
			if (!phi_is_philo_full(&(data->philos[i]))
				&& phi_is_philo_dead(&(data->philos[i])))
			{
				phi_print(data, data->philos[i].id, "died");
				return ;
			}
			i++;
		}
		usleep(1000);
	}
}

void	phi_check_death(t_data *data)
{
	phi_wait_for_first_death(data);
	pthread_mutex_lock(&(data->one_died_mutex));
	data->one_died = 1;
	pthread_mutex_unlock(&(data->one_died_mutex));
}
