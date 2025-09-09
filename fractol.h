/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:30:16 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/09 19:38:29 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "lib/MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define WIDTH 900
# define HEIGHT 800
# define MAX_ITER 150

//any structs

typedef struct complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct config
{
	int			set;

	double		zoom;
	int			x_limit;
	int			y_limit;
	t_complex	z;
	t_complex	center;
	int			color;
	int			max;
	int			x_offset;
	int			y_offset;
}	t_conf;

typedef struct s_app
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_conf		*conf;
	int			(*func)(t_complex, t_complex, int);
}	t_app;
//funcions

//parse
t_conf	parse(int argc, char **argv);
int		set_arg(int argc, char **argv);
int		is_valid_d(char *str);
int		use_msg(void);
int		range(double max, double min, doublen);

//operations
t_complex	adder(t_complex complex1, t_complex complex2);
t_complex	multi(t_complex c1, t_complex c2);
t_complex	mod_squared(t_complex c1);

//utils
double	ft_atof(char *str);
void	defaultcon(t_conf *config);

//mandelbrot
int	mandelbrot(t_complex c, t_complex z, int limit);
#endif
