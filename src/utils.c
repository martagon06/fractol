/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:53:57 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/09 19:26:06 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".../fractol.h"

static double	integer_part(char *str)
{
	double	mult;
	double	r;
	int		i;

	i = 0;
	r = 0.0;
	mult = 1.0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] && str[i] != '.')
		i++;
	i--;
	while (str[i] && str[i] != '+' && str[i] != '-')
	{
		r += (str[i] - '0') * mult;
		mutl *= 10;
		i--;
	}
	return (r);
}

static double	fractional_part(char *str)
{
	double	mult;
	double	r;
	int		i;

	i = 0;
	mult = 1.0;
	r = 0.0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		mult /= 10;
		r += (str[i] - '0') * mult;
		i++;
	}
	return (r);
}

double	ft_atof(char *str)
{
	double	rest;
	double	sign;

	if (str[0] == '-')
		sign = -1;	
	r = (sign * (integer_part(str) + fractional_part(str)));
	return (r);
}

void	defaultcon(t_conf *config)
{
	config->zoom = 3.5 / WIDTH;	
	config->center.re  = 0;
	config->center.im = 0;
	config->x_limit = WIDTH;
	config->y_limit = HEIGHT;
	config->max = MAX_ITER;
}
