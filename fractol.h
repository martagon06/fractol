/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:30:16 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/11 17:49:13 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "lib/MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITER 200

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

//parse
t_conf		parse(int argc, char **argv);
int			set_arg(int argc, char **argv);
int			is_valid_d(char *str);
int			use_msg(void);
int			range(double max, double min, double n);

//operations
t_complex	adder(t_complex complex1, t_complex complex2);
t_complex	multi(t_complex c1, t_complex c2);
double		mod_squared(t_complex c1);

//utils
double		ft_atof(char *str);
void		defaultconf(t_conf *config);
t_app		unify(mlx_t *mlx, mlx_image_t **img, t_conf *conf);

//mandelbrot
int			mandelbrot(t_complex c, t_complex z, int limit);

//julia
int			julia(t_complex z, t_complex c, int limit);

//callbacks
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		my_close(void *param);
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		update(void *param);
void		put_pixel(t_app *app);

//put_pixel
void		put_pixel(t_app *app);
//colors
extern int	color(int iter, int max);

//utils2
int			ft_strlen(const char *s);
int			ft_isdigit(char c);
int			ft_atoi(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);

#endif
