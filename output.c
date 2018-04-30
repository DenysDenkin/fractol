/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:26:05 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/31 18:13:57 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		choose_fractal(t_mlx *mlx, char *s)
{
	if (ft_strcmp(s, "Julia") == 0)
		mlx->frac = julia;
	else if ((ft_strcmp(s, "Mandelbrot") == 0))
		mlx->frac = mand;
	else if ((ft_strcmp(s, "Ship") == 0))
		mlx->frac = ship;
	else if ((ft_strcmp(s, "Tricorn") == 0))
		mlx->frac = tricorn;
	else if ((ft_strcmp(s, "Carpet") == 0))
		mlx->frac = carpet;
	else if ((ft_strcmp(s, "Cubebrot") == 0))
		mlx->frac = cubebrot;
	else if ((ft_strcmp(s, "Quadrabrot") == 0))
		mlx->frac = quadrabrot;
	else if ((ft_strcmp(s, "Pentabrot") == 0))
		mlx->frac = pentabrot;
	else
		return (-1);
	(mlx->frac == mand) ? mlx->x = -550 : 1;
	(mlx->frac == mand) ? mlx->y = -350 : 1;
	return (1);
}

void	free_help(t_help help)
{
	free(help.x);
	free(help.y);
	free(help.z);
	free(help.mx);
	free(help.my);
	free(help.max_i);
}

int		usage(void)
{
	ft_putstr("Usage: ./fractol [Julia|Mandelbrot|Ship|Tricorn|"
					"Carpet|Cubebrot|Quadrabrot|Pentabrot]+\n");
	return (0);
}
