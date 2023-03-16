/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/01/30 14:22:25 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	phi_init(t_data *data)
{
	data->philo_nb = -1;
	data->die_time = -1;
	data->eat_time = -1;
	data->sleep_time = -1;
	data->meals_max = -1;
	data->philos = NULL;
	data->time_0 = -1;
	data->one_died = 0;
	data->forks = NULL;
}
