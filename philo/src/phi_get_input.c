/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_get_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:01:12 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/23 11:39:09 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	phi_is_int(char *s)
{
	char	*int_max_str;
	char	*abs;
	int		is_neg;
	int		is_overflowed;

	if (!s || !*s)
		return (0);
	is_neg = (*s == '-');
	if ((*s == '-' || *s == '+') && ft_isdigit(*(s + 1)))
		s++;
	while (*s == '0' && ft_isdigit(*(s + 1)))
		s++;
	abs = s;
	while (ft_isdigit(*s))
		s++;
	if (*s)
		return (0);
	int_max_str = ft_itoa(INT_MAX);
	is_overflowed = (ft_strlen(abs) > ft_strlen(int_max_str) \
		|| (ft_strlen(abs) == ft_strlen(int_max_str) \
		&& ft_strncmp(abs, int_max_str, ft_strlen(int_max_str)) > is_neg));
	free(int_max_str);
	return (!is_overflowed);
}

void	phi_get_input(t_data *data, int argc, char **argv)
{
	int	i;

	if (argc < 5)
		phi_error_exit(data, "Too few arguments");
	if (argc > 6)
		phi_error_exit(data, "Too many arguments");
	i = 1;
	while (i < argc)
	{
		if (!phi_is_int(argv[i]))
			phi_error_exit(data, "Invalid arguments");
		i++;
	}
	data->philo_nb = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->meals_max = ft_atoi(argv[5]);
	else
		data->meals_max = -1;
	if (data->philo_nb < 1 || data->die_time < 0 || data->eat_time < 0
		|| data->sleep_time < 0 || (argc == 6 && data->meals_max < 0))
		phi_error_exit(data, "Invalid arguments");
}
