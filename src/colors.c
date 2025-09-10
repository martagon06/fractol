/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:56:27 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/10 21:03:57 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

inline int	color(int iter, int max)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	double			t;

	if (iter == max)
		return (0x000000FF);
	t = (double)iter / max;
	r = (unsigned char)(sin(5 * t * 3.1415) * 127 + 128);
	g = (unsigned char)(sin(5 * t * 3.1415 + 2) * 127 + 128);
	b = (unsigned char)(sin(5 * t * 3.1415 * 4) * 127 + 128);
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}
