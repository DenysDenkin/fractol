/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:27:00 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/31 17:43:12 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			cubebrot(t_mlx *mlx, long x, long y)
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
		m.nr = m.cr * m.cr * m.cr - 3 * m.cr * m.ci * m.ci + m.op;
		m.ci = 3 * m.cr * m.cr * m.ci - m.ci * m.ci * m.ci + m.oi;
		m.cr = m.nr;
		if (m.cr * m.cr + m.ci * m.ci >= 4)
			break ;
		iter++;
	}
	return (iter);
}

int			tricorn(t_mlx *mlx, long x, long y)
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
		m.nr = m.cr * m.cr - m.ci * m.ci + m.op;
		m.ci = -2 * m.cr * m.ci + m.oi;
		m.cr = m.nr;
		if (m.cr * m.cr + m.ci * m.ci >= 4)
			break ;
		iter++;
	}
	return (iter);
}

int			ship(t_mlx *mlx, long x, long y)
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
		m.nr = m.cr * m.cr - m.ci * m.ci + m.op;
		m.ci = fabsl(2 * m.cr * m.ci + m.oi);
		m.cr = fabsl(m.nr);
		if (m.cr * m.cr + m.ci * m.ci >= 4)
			break ;
		iter++;
	}
	return (iter);
}

int			julia(t_mlx *mlx, long x, long y)
{
	t_mandel	m;
	int			iter;
	static int	mx;
	static int	my;

	iter = 0;
	mx = (mlx->mouse_active == 1) ? mlx->mouse_x : mx;
	my = (mlx->mouse_active == 1) ? mlx->mouse_y : my;
	m.cr = (double)x / mlx->z - 2;
	m.ci = (double)y / mlx->z - 2;
	while (iter < mlx->max_iter)
	{
		m.op = m.cr;
		m.cr = m.cr * m.cr - m.ci * m.ci + (0.5 * mx / WIN_W);
		m.ci = 2 * m.op * m.ci + 0.27015 * my / WIN_H;
		if (m.cr * m.cr + m.ci * m.ci >= 4)
			break ;
		iter++;
	}
	return (iter);
}

int			mand(t_mlx *mlx, long x, long y)
{
	t_mandel	m;
	int			iter;

	iter = 0;
	m.cr = (double)x / mlx->z;
	m.ci = (double)y / mlx->z;
	m.nr = m.cr;
	m.ni = m.ci;
	while (iter < mlx->max_iter)
	{
		m.op = m.nr;
		m.nr = m.op * m.op - m.ni * m.ni + m.cr;
		m.ni = 2 * m.op * m.ni + m.ci;
		if (m.nr * m.nr + m.ni * m.ni >= 4)
			break ;
		iter++;
	}
	return (iter);
}
