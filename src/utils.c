/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:53:57 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/11 13:40:33 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <string.h>

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
	while (i >= 0 && str[i] != '+' && str[i] != '-')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			r += (str[i] - '0') * mult;
			mult *= 10;
		}
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
	double	sign;
	double	r;

	if (!str || *str == '\0')
		return (0.0);
	if (!strpbrk(str, "0123456789"))
		return (0.0);
	sign = 1.0;
	if (str[0] == '-')
		sign = -1.0;
	r = (sign * (integer_part(str) + fractional_part(str)));
	return (r);
}

void	defaultconf(t_conf *config)
{
	config->zoom = 3.5 / WIDTH;
	config->center.re = 0;
	config->center.im = 0;
	config->x_limit = WIDTH;
	config->y_limit = HEIGHT;
	config->max = MAX_ITER;
}

t_app	unify(mlx_t *mlx, mlx_image_t **img, t_conf *conf)
{
	t_app	r;

	r.mlx = mlx;
	r.img = *img;
	r.conf = conf;
	if (conf->set == 1)
		r.func = mandelbrot;
	else
		r.func = julia;
	return (r);
}
