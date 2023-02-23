/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:52:23 by dapereir          #+#    #+#             */
/*   Updated: 2023/02/23 12:04:31 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo {
	int			id;
	int			left_fork;
	int			right_fork;
	pthread_t	thread;
}				t_philo;

typedef struct s_data {
	int				philo_nb;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_nb;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}				t_data;

// ft
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

// utils
void	phi_init(t_data *data);
void	phi_reset(t_data *data);
void	phi_error_exit(t_data *data, char *msg);
void	phi_error_exit_if(t_data *data, char *msg, int condition);

// philo
void	phi_init_data(t_data *data);
void	phi_get_input(t_data *data, int argc, char **argv);

#endif