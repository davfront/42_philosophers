/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:52:23 by dapereir          #+#    #+#             */
/*   Updated: 2023/03/06 13:26:15 by dapereir         ###   ########.fr       */
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
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	double			last_meal;
	int				meals;
	pthread_t		thread;
	struct s_data	*data;
}				t_philo;

typedef struct s_data {
	int				philo_nb;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				meals_max;
	t_philo			*philos;
	double			time_0;
	int				one_died;
	pthread_mutex_t	one_died_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
}				t_data;

// ft
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);

// utils
void	phi_init(t_data *data);
void	phi_reset(t_data *data);
void	phi_error_exit(t_data *data, char *msg);
void	phi_error_exit_if(t_data *data, char *msg, int condition);
double	phi_absolute_time(void);
double	phi_time(t_data *data);
void	phi_print(t_data *data, int id, char *msg);

// philo
void	phi_init_data(t_data *data);
void	phi_get_input(t_data *data, int argc, char **argv);
int		phi_is_philo_full(t_philo *philo);
int		phi_is_philo_dead(t_philo *philo);
void	*phi_philo_routine(void *void_philo);
void	phi_create_data(t_data *data);
void	phi_start_threads(t_data *data);

#endif