/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:57:34 by dapereir          #+#    #+#             */
/*   Updated: 2023/03/06 13:25:36 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	phi_print(t_data *data, int id, char *msg)
{
	if (data->one_died)
		return ;
	pthread_mutex_lock(&(data->print_mutex));
	printf("%.0f %i %s\n", phi_time(data), id, msg);
	pthread_mutex_unlock(&(data->print_mutex));
}
