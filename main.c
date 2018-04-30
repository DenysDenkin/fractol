/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:58:44 by ddenkin           #+#    #+#             */
/*   Updated: 2018/03/31 19:08:05 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	magic_color(t_mlx *mlx, long x, long y, int iter)
{
	if (iter != mlx->max_iter && mlx->epylepsy_active == 1 && iter > 0)
		mlx->addr[(y - mlx->y) * WIN_W + (x - mlx->x)] = (0x013042 * iter +
				mlx->mouse_x * mlx->mouse_y) % 0x00FF00;
	else if (iter != mlx->max_iter && iter > 0)
		mlx->addr[(y - mlx->y) * WIN_W + (x - mlx->x)] = (0x013042 * iter)
														% 0x00FF00;
	else
		mlx->addr[(y - mlx->y) * WIN_W + (x - mlx->x)] = 0x000000;
}

void	*task(void *a)
{
	long		i;
	long		j;
	t_pth_arg	*arg;

	arg = (t_pth_arg *)a;
	i = arg->x_s - 1;
	while (++i < arg->x_e)
	{
		j = arg->y_s - 1;
		while (++j < arg->y_e)
			magic_color(arg->mlx, i, j, arg->mlx->frac(arg->mlx, i, j));
	}
	free(a);
	pthread_exit(0);
}

void	put_help(t_mlx mlx)
{
	t_help	h;

	mlx_string_put(mlx.mlx, mlx.win, 3, 0, 0x00FF00, "Max iter:");
	mlx_string_put(mlx.mlx, mlx.win, 150, 0, 0x00FF00,
				h.max_i = ft_itoa(mlx.max_iter));
	mlx_string_put(mlx.mlx, mlx.win, 3, 15, 0x00FF00, "Zoom:");
	mlx_string_put(mlx.mlx, mlx.win, 150, 15, 0x00FF00, h.z = ft_itoa(mlx.z));
	mlx_string_put(mlx.mlx, mlx.win, 3, 30, 0x00FF00, "X:");
	mlx_string_put(mlx.mlx, mlx.win, 150, 30, 0x00FF00, h.x = ft_itoa(-mlx.x));
	mlx_string_put(mlx.mlx, mlx.win, 3, 45, 0x00FF00, "Y:");
	mlx_string_put(mlx.mlx, mlx.win, 150, 45, 0x00FF00, h.y = ft_itoa(mlx.y));
	mlx_string_put(mlx.mlx, mlx.win, 3, 60, 0x00FF00, "Mouse X:");
	mlx_string_put(mlx.mlx, mlx.win, 150, 60, 0x00FF00,
				h.mx = ft_itoa(mlx.mouse_x));
	mlx_string_put(mlx.mlx, mlx.win, 3, 75, 0x00FF00, "Mouse Y:");
	mlx_string_put(mlx.mlx, mlx.win, 150, 75, 0x00FF00,
				h.my = ft_itoa(mlx.mouse_y));
	mlx_string_put(mlx.mlx, mlx.win, 3, 90, 0x00FF00, "Mouse(Julia):");
	mlx_string_put(mlx.mlx, mlx.win, 150, 90, 0x00FF00, (mlx.mouse_active) ?
												"Active" : "Not active");
	mlx_string_put(mlx.mlx, mlx.win, 3, 105, 0x00FF00, "Disco mode:");
	mlx_string_put(mlx.mlx, mlx.win, 150, 105, 0x00FF00, (mlx.epylepsy_active) ?
												"Active" : "Not active");
	free_help(h);
}

void	putallthepixels(t_mlx mlx)
{
	t_abc		t;
	pthread_t	child[PROC];
	t_pth_arg	*args;
	int			i;

	mlx.addr = (int *)mlx_get_data_addr(mlx.img, &t.a, &t.b, &t.c);
	i = -1;
	while (++i < PROC)
	{
		args = (t_pth_arg *)malloc(sizeof(t_pth_arg));
		args->mlx = &mlx;
		args->addr = mlx.addr;
		args->x_s = mlx.x + WIN_W * (i % PR_SQRT) / PR_SQRT;
		args->x_e = mlx.x + WIN_W * (i % PR_SQRT) / PR_SQRT + WIN_W / PR_SQRT;
		args->y_s = mlx.y + WIN_H * (i / PR_SQRT) / PR_SQRT;
		args->y_e = mlx.y + WIN_H * (i / PR_SQRT) / PR_SQRT + WIN_H / PR_SQRT;
		pthread_create(&(child[i]), NULL, task, args);
	}
	i = -1;
	while (++i < PROC)
		pthread_join(child[i], NULL);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	put_help(mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		i;

	if (argc < 2 && (i = 1) == 1)
		return (usage());
	if (argc > 2)
	{
		while (i < argc - 1 && fork())
			i++;
		execv(argv[0], (char *[]) {argv[0], argv[i], NULL});
	}
	mlx = init_all();
	if (choose_fractal(mlx, argv[1]) == -1)
		return (usage());
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H,
				(mlx->name = ft_strjoin("Fractal ", argv[1])));
	mlx->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	putallthepixels(*mlx);
	mlx_hook(mlx->win, 2, 5, hook_keypress, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, cross, mlx);
	mlx_hook(mlx->win, 6, 1 << 6, hook_mousemove, mlx);
	mlx_mouse_hook(mlx->win, hook_mouseclick, mlx);
	mlx_loop(mlx->mlx);
}
