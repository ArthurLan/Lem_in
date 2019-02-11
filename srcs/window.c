/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:14:43 by alanter           #+#    #+#             */
/*   Updated: 2018/10/26 13:46:01 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include "lem_in.h"

void		ft_new_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->img.img = (unsigned int*)mlx_get_data_addr(mlx->img.img_ptr,
			&(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));
	draw_back(&mlx->img, 1);
	draw_rooms(mlx, mlx->info);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	draw_ants(mlx, mlx->info);
	draw_str(mlx);
}

int			loop_path(t_mlx *mlx)
{
	if (mlx->speed != 900000)
	{
		usleep(mlx->speed);
		move_ants(mlx->info);
		if (mlx->info->done != 1)
			mlx->info->nb_inst++;
		ft_new_image(mlx);
	}
	else
		ft_new_image(mlx);
	return (0);
}

int			deal_key(int key, t_mlx *mlx)
{
	if (key == 46)
	{
		mlx->menu = (mlx->menu == 0) ? 1 : 0;
		ft_new_image(mlx);
	}
	if (key == 35)
		mlx->speed = 900000;
	if (key == 15)
		start_again(mlx->info);
	if (key == 124 && mlx->speed > 100000)
	{
		mlx->speed -= 200000;
		mlx_loop_hook(mlx->mlx_ptr, loop_path, mlx);
	}
	if (key == 123 && mlx->speed < 900000)
	{
		mlx->speed += 200000;
		mlx_loop_hook(mlx->mlx_ptr, loop_path, mlx);
	}
	if (key == 53)
		exit(0);
	return (0);
}

static int	rand_ground(t_mlx *mlx)
{
	int i;

	i = 0;
	if (!(mlx->img.rand = ft_memalloc(sizeof(char) * 9999999)))
		return (0);
	while (i < 9999998)
		mlx->img.rand[++i] = rand();
	return (1);
}

void		*window(t_info *info)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (info)
		;
	mlx->info = info;
	mlx->speed = 900000;
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H, "Lem-in");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->img.img = (unsigned int*)mlx_get_data_addr(mlx->img.img_ptr,
			&(mlx->img.size_l), &(mlx->img.bpp), &(mlx->img.endian));
	calc_coord(info);
	rand_ground(mlx);
	draw_back(&mlx->img, 1);
	draw_rooms(mlx, info);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	draw_ants(mlx, info);
	draw_str(mlx);
	mlx_key_hook(mlx->win, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
	ft_memdel((void**)&mlx->img.rand);
	ft_memdel((void**)&mlx);
	return (NULL);
}
