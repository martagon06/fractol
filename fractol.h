/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:30:16 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/09 13:07:26 by miguelmo         ###   ########.fr       */
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

#endif