/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:27:23 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/09 19:37:50 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".../fractol.h"

int	mandelbrot(t_complex c, t_complex z, int limit)
{
	t_complex	temp;
	int			i;

	(void)z;
	i = 0;
	temp.re = 0;
	temp.im = 0;
	while (mod_squared(temp) <= 4 && i < limit)
	{
		temp = add(mult(temp, temp), c);
		i++;
	}
	return (i);
}
