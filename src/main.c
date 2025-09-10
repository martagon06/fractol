/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:44:49 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/10 21:32:08 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static	void	ft_error(void)
{
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_conf		conf;
	t_app		app;

	conf = parse(argc, argv);
	defaultconf(&conf);
	mlx = mlx_init(conf.x_limit, conf.y_limit, "Fractol", false);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, conf.x_limit, conf.y_limit);
	app = unify(mlx, &img, &conf);
	mlx_key_hook(mlx, my_keyhook, &app);
	mlx_close_hook(mlx, my_close, &app);
	mlx_scroll_hook(mlx, &my_scrollhook, &app);
	mlx_loop_hook(mlx, update, &app);
	put_pixel(&app);
}
