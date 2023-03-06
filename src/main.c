/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:48:23 by dapereir          #+#    #+#             */
/*   Updated: 2023/03/06 13:26:58 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int	main(int argc, char **argv)
{
	t_data	data;

	phi_init(&data);
	phi_get_input(&data, argc, argv);
	phi_create_data(&data);
	phi_start_threads(&data);
	phi_reset(&data);
	return (EXIT_SUCCESS);
}
