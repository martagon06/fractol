/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:40:00 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/09 17:52:02 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	range(double max, double min, double n)
{
	if(n  <= max && n >= min)
		return (1);
	else
		return (0);
}

int use_msg(void)
{
	(void)!write(1, "use\n", 4);
	(void)!write(1, "Sets: 1(Mandelbrot), 2(Julia)\n", 30);
	(void)!write(1, "(just for Julia) set, n(re), n(im)", 34);
	(void)!write(1, "c range = (2, -2)\n", 18);
}

int set_arg(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] == '1')
		return (1);
	else if (argc == 4 && argcv[2][0] == '2')
		return (2);
	else
		exit (use_msg());	
}

int	is_valid_d(char *str)
{
	int	i;
	int dot

	i = 0;
	dot = 0;
	if(ft_strlen(str) > 32)
		return (0);
	if(str[0] == '+' || str[0] == '-')
		i++;
	while(str[i])
	{
		if(str[i] < '0' || str[i] > '9')
		{
			if(str[i] == '.' && dot == 0)
				dot++;
			else 
				return (0);
		}
		i++
	}
	return (1);
}

t_conf parse(int argc, char **argv)
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
		if(!(is_valid_d(argv[2]) || !is_valid_d(argv[3])))
			exit(use_masg());
		r.z.re = ft_atod(argv[2]);
		r.z.im = ft_atod(argv[3]);
	}
	if (!range(2.0 , -2.0, r.z.re) || !range(2.0, -2.0, r.z.im))
		exit(use_msg());
	return (r);
}
