/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_error_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:20 by dapereir          #+#    #+#             */
/*   Updated: 2023/01/30 14:22:25 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	phi_error_exit(t_data *data, char *msg)
{
	ft_putstr_fd("Error", STDERR_FILENO);
	if (msg && *msg)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	phi_reset(data);
	exit(EXIT_FAILURE);
}

void	phi_error_exit_if(t_data *data, char *msg, int condition)
{
	if (condition)
		phi_error_exit(data, msg);
}
