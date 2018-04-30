/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:52:15 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/31 17:13:54 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mlx_clear_image(t_mlx *mlx)
{
	int			*addr;
	int			a;
	int			b;
	int			c;

	addr = (int *)mlx_get_data_addr(mlx->img, &a, &b, &c);
	ft_bzero(addr, WIN_H * WIN_W * 4);
}

int			cross(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
}

int			hook_keypress(int key, t_mlx *mlx)
{
	(key == ESC) ? exit(0) : 0;
	if (key == MOUSE_ACTIVE)
		mlx->mouse_active ^= 1;
	else if (key == RIGHT)
		mlx->x -= 100;
	else if (key == LEFT)
		mlx->x += 100;
	else if (key == UP)
		mlx->y += 100;
	else if (key == DOWN)
		mlx->y -= 100;
	else if (key == INCR_ITER)
		mlx->max_iter += 10;
	else if (key == DECR_ITER)
		mlx->max_iter = ft_max(mlx->max_iter - 10, 10);
	else if (key == KEY_ZOOM)
		zoom(mlx);
	else if (key == KEY_UNZOOM)
		unzoom(mlx);
	else if (key == EPYLEPSY)
		mlx->epylepsy_active ^= 1;
	mlx_clear_image(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	putallthepixels(*mlx);
	return (0);
}
