/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:40:00 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/11 13:51:28 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <unistd.h>

int	range(double max, double min, double n)
{
	if (n <= max && n >= min)
		return (1);
	else
		return (0);
}

int	use_msg(void)
{
	write(2, "Usage:\n", sizeof("Usage:\n") - 1);
	write(2, "  fractol 1", sizeof("  fractol 1") - 1);
	write(2, "\t\t# Mandelbrot\n", sizeof("\t\t# Mandelbrot\n") - 1);
	write(2, "  fractol 2 <re> <im>", sizeof("  fractol 2 <re> <im>") - 1);
	write(2, "\t# Julia\n", sizeof("\t# Julia\n") - 1);
	write(2, " with complex c\n", sizeof("    with complex c\n") - 1);
	write(2, "(re, im) in [-2,2]\n", sizeof("    (re, im) in [-2,2]\n") - 1);
	return (1);
}

int	set_arg(int argc, char *argv[])
{
	if (argc == 2 && ft_strcmp(argv[1], "1") == 0)
		return (1);
	else if (argc == 4 && ft_strcmp(argv[1], "2") == 0)
		return (2);
	exit(use_msg());
}

int	is_valid_d(char *str)
{
	int	i;
	int	dot;
	int	has_digit;

	i = 0;
	dot = 0;
	has_digit = 0;
	if (ft_strlen(str) > 32)
		return (0);
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			has_digit = 1;
		else if (str[i] == '.' && dot == 0)
			dot++;
		else
			return (0);
		i++;
	}
	if (!has_digit)
		return (0);
	return (1);
}

t_conf	parse(int argc, char *argv[])
{
	t_conf		r;
	t_complex	z;

	z.re = 0.0;
	z.im = 0.0;
	r.set = 0;
	r.z = z;
	r.set = set_arg(argc, argv);
	if (r.set == 2)
	{
		if (!(is_valid_d(argv[2]) && is_valid_d(argv[3])))
			exit(use_msg());
		r.z.re = ft_atof(argv[2]);
		r.z.im = ft_atof(argv[3]);
	}
	if (!range(2.0, -2.0, r.z.re) || !range(2.0, -2.0, r.z.im))
		exit(use_msg());
	return (r);
}
