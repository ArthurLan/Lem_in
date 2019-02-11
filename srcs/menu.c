/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 08:57:22 by alanter           #+#    #+#             */
/*   Updated: 2018/10/26 12:48:07 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	menu(t_mlx *mlx, int c)
{
	if (mlx->menu == 0)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W - 120, 2, c, "M   : Menu");
	if (mlx->menu == 1)
	{
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 2, c, "M   : Close");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 20, c, "->  : Speed up");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 38, c, "<-  : Speed down");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 54, c, "P   : Pause");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 74, c, "R   : Reset");
		mlx_string_put(mlx->mlx_ptr,
				mlx->win, WIN_W - 190, 92, c, "Esc : Quit");
	}
}

void	draw_str(t_mlx *mlx)
{
	int		c;
	char	*nb_i;

	c = 0x000040;
	nb_i = ft_itoa(mlx->info->nb_inst);
	mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W - 70, WIN_H - 30, c, nb_i);
	ft_memdel((void**)&nb_i);
	if (mlx->speed == 100000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X100");
	else if (mlx->speed == 300000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X10");
	else if (mlx->speed == 500000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X1");
	else if (mlx->speed == 700000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X0.1");
	else if (mlx->speed == 900000)
		mlx_string_put(mlx->mlx_ptr, mlx->win, WIN_W / 50, 5, c, "X0");
	menu(mlx, c);
}
