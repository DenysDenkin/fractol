/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:42:58 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/31 18:16:19 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			carpet(t_mlx *mlx, long x, long y)
{
	x = labs(x);
	y = labs(y);
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);
		x /= 3;
		y /= 3;
	}
	return (mlx->max_iter);
}

int			quadrabrot(t_mlx *mlx, long x, long y)
{
	t_mandel	m;
	int			iter;

	iter = 0;
	m.op = (double)x / mlx->z - 2;
	m.oi = (double)y / mlx->z - 2;
	m.cr = 0;
	m.ci = 0;
	while (iter < mlx->max_iter)
	{
		m.nr = m.cr * m.cr * m.cr * m.cr - 6 * m.cr * m.cr * m.ci * m.ci + m.ci
													* m.ci * m.ci * m.ci + m.op;
		m.ci = 4 * m.cr * m.cr * m.cr * m.ci - 4 * m.cr * m.ci * m.ci * m.ci
																		+ m.oi;
		m.cr = m.nr;
		if (m.cr * m.cr + m.ci * m.ci >= 4)
			break ;
		iter++;
	}
	return (iter);
}

int			pentabrot(t_mlx *mlx, long x, long y)
{
	t_mandel	m;
	int			iter;

	iter = 0;
	m.op = (double)x / mlx->z - 2;
	m.oi = (double)y / mlx->z - 2;
	m.cr = 0;
	m.ci = 0;
	while (iter < mlx->max_iter)
	{
		m.nr = m.cr * m.cr * m.cr * m.cr * m.cr - 10 * m.cr * m.cr * m.cr * m.ci
						* m.ci + 5 * m.cr * m.ci * m.ci * m.ci * m.ci + m.op;
		m.ci = 5 * m.cr * m.cr * m.cr * m.cr * m.ci - 10 * m.cr * m.cr * m.ci *
						m.ci * m.ci + m.ci * m.ci * m.ci * m.ci * m.ci + m.oi;
		m.cr = m.nr;
		if (m.cr * m.cr + m.ci * m.ci >= 4)
			break ;
		iter++;
	}
	return (iter);
}
