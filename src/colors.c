/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:56:27 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/11 13:55:45 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	color(int iter, int max)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	double			t;

	if (iter >= max)
		return (0x000000FF);
	t = (double)iter / (double)max;
	r = (unsigned char)(sin(5 * t * 3.1415) * 127 + 128);
	g = (unsigned char)(sin(5 * t * 3.1415 + 2) * 127 + 128);
	b = (unsigned char)(sin(5 * t * 3.1415 * 4) * 127 + 128);
	return (((int)r << 24) | ((int)g << 16) | ((int)b << 8) | 0xFF);
}
