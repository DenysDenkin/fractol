/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:52:23 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/30 17:50:18 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom(t_mlx *mlx)
{
	if ((long)((mlx->x + mlx->mouse_x / 5) * 1.2) < -1000000000000L ||
	(long)((mlx->y + mlx->mouse_y / 5) * 1.2) < -1000000000000L ||
	(long)(mlx->z * 1.2) < -1000000000000L)
		return ;
	mlx->x += mlx->mouse_x / 7;
	mlx->y += mlx->mouse_y / 7;
	mlx->z *= 1.15;
	mlx->y *= 1.15;
	mlx->x *= 1.15;
}

void		unzoom(t_mlx *mlx)
{
	if (mlx->z <= 10)
		return ;
	mlx->x -= mlx->mouse_x / 7;
	mlx->y -= mlx->mouse_y / 7;
	mlx->z /= 1.15;
	mlx->y /= 1.15;
	mlx->x /= 1.15;
}

int			hook_mouseclick(int button, int x, int y, t_mlx *mlx)
{
	if (x < 0 || x >= WIN_W || y < 0 || y > WIN_H)
		return (0);
	if (button == MOUSE_ZOOM)
		zoom(mlx);
	else if (button == MOUSE_UNZOOM)
		unzoom(mlx);
	mlx_clear_image(mlx);
	putallthepixels(*mlx);
	return (0);
}

int			hook_mousemove(int x, int y, t_mlx *mlx)
{
	if (x < 0 || x >= WIN_W || y < 0 || y > WIN_H)
		return (0);
	mlx->mouse_x = x;
	mlx->mouse_y = y;
	mlx_clear_image(mlx);
	putallthepixels(*mlx);
	return (0);
}
