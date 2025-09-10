/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:45:00 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/10 20:55:09 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	put_pixel(t_app *app)
{
	int			x;
	int			y;
	t_complex	pos;

	y = -1;
	x = -1;
	while (++y < app->conf->y_limit)
	{
		pos.im = ((y - (app->conf->y_limit / 2)) * app->conf->zoom)
			+ app->conf->center.im;
		x = 0;
		while (++x < app->conf->x_limit)
		{
			pos.re = ((x - (app->conf->x_limit / 2)) * app->conf->zoom)
				+ app->conf->center.re;
			mlx_put_pixel(app->img, x, y, color(app->func(pos,
						app->conf->z, app->conf->max), app->conf->max));
		}
	}
	return ;
}
