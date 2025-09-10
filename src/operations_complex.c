/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_complex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:42:57 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/10 20:28:56 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex	adder(t_complex complex1, t_complex complex2)
{
	t_complex	r;

	r.re = complex1.re + complex2.re;
	r.im = complex1.im + complex2.im;
	return (r);
}

t_complex	multi(t_complex c1, t_complex c2)
{
	t_complex	r;

	r.re = c1.re * c2.re - (c1.im * c2.im);
	r.im = c1.re * c2.im + (c1.im * c2.re);
	return (r);
}

double	mod_squared(t_complex c1)
{
	return (c1.re * c1.re + c1.im * c1.im);
}
