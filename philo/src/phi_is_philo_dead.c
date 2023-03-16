/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_is_philo_dead.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/03/06 13:38:43 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	phi_is_philo_dead(t_philo *philo)
{
	double	t;
	t_data	*data;
	int		is_dead;

	data = philo->data;
	t = phi_absolute_time();
	pthread_mutex_lock(&(philo->last_meal_mutex));
	is_dead = (t - philo->last_meal) > (double)(data->die_time);
	pthread_mutex_unlock(&(philo->last_meal_mutex));
	return (is_dead);
}
