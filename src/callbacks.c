/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:38:18 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/11 13:28:42 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	update(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	mlx_image_to_window(app->mlx, app->img, 0, 0);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	(void)xdelta;
	if (ydelta < 0)
		app->conf->zoom *= 1.1;
	else if (ydelta > 0)
		app->conf->zoom /= 1.1;
	if (app->conf->zoom < 1e-12)
		app->conf->zoom = 1e-12;
	if (app->conf->zoom > 1e6)
		app->conf->zoom = 1e6;
	put_pixel(app);
}

void	my_close(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	mlx_delete_image(app->mlx, app->img);
	mlx_terminate(app->mlx);
	exit(0);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		my_close(param);
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		app->conf->center.im -= 10 * app->conf->zoom;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		app->conf->center.im += 10 * app->conf->zoom;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		app->conf->center.re -= 10 * app->conf->zoom;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		app->conf->center.re += 10 * app->conf->zoom;
	put_pixel(app);
}
