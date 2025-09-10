/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:11:44 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/10 20:29:14 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	julia(t_complex z, t_complex c, int limit)
{
	int	i;

	i = 0;
	while (mod_squared(z) <= 4 && i < limit)
	{
		z = adder(multi(z, z), c);
		i++;
	}
	return (i);
}
