/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:25:21 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/31 17:00:43 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*init_all(void)
{
	t_mlx	*res;

	res = (t_mlx *)malloc(sizeof(t_mlx));
	res->mlx = 0;
	res->win = 0;
	res->img = 0;
	res->name = 0;
	res->max_iter = 50;
	res->mouse_active = 0;
	res->epylepsy_active = 0;
	res->mouse_x = WIN_W / 2;
	res->mouse_y = WIN_H / 2;
	res->x = -200;
	res->y = -100;
	res->z = 150;
	res->zr = -0.7;
	res->zi = 0.27015;
	return (res);
}
