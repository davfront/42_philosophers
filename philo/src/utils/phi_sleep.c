/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:50:18 by dapereir          #+#    #+#             */
/*   Updated: 2023/03/16 16:49:07 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	phi_sleep(t_data *data, int ms)
{
	int	one_died;

	pthread_mutex_lock(&(data->one_died_mutex));
	one_died = data->one_died;
	pthread_mutex_unlock(&(data->one_died_mutex));
	if (one_died)
		return ;
	usleep(ms * 1000);
}
