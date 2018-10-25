/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 04:25:21 by alanter           #+#    #+#             */
/*   Updated: 2018/10/25 19:48:10 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		draw_back(t_img *img, int i)
{
	int x;
	int y;

	x = -1;
	while (++x < WIN_W)
	{
		y = -1;
		while (++y < WIN_H)
		{
			if ((y < WIN_H / 7))
				img->img[y * WIN_W + x] = 0x27AEE3;
			else if (y >= WIN_H / 7 && y < WIN_H / 6)
				img->img[y * WIN_W + x] = 0x397628;
			else
			{
				img->img[y * WIN_W + x] = 0x5F472F;
				if (img->rand[++i] % 182 == 0)
					img->img[y * WIN_W + x] = 0x5F5C58;
				else if (img->rand[i] % 128 == 0)
					img->img[y * WIN_W + x] = 0xB1ADA5;
			}
		}
		if (i > 999999)
			i = 1;
	}
}

static void	fill_pixel(unsigned int *img, int x, int y)
{
	int big;

	big = 0;
	y += 30;
	x += 30;
	while (big < 8)
	{
		if (x < WIN_W && y + big < WIN_H && x >= 30 && y + big >= 30)
			img[y * WIN_W + (x + big)] = 0x442525;
		big++;
	}
	big = 0;
	while (big < 8)
	{
		if (x < WIN_W && y + big < WIN_H && x >= 30 && y + big >= 30)
			img[(y + big) * WIN_W + x] = 0x442525;
		big++;
	}
}

static void	draw_line(unsigned int *img, t_room a, t_room b)
{
	int ex;
	int ey;
	int err;
	int e;

	ex = abs(b.x - a.x);
	ey = abs(b.y - a.y);
	err = (ex > ey ? ex : -ey) / 2;
	while (a.x != b.x || a.y != b.y)
	{
		e = err;
		fill_pixel(img, a.x, a.y);
		if (e > -ex && (err -= ey) != 1e-9)
			a.x > b.x ? a.x-- : a.x++;
		if (e < ey && (err += ex) != 1e-9)
			a.y > b.y ? a.y-- : a.y++;
	}
	fill_pixel(img, a.x, a.y);
}

void		draw_room(unsigned int *img, int rx, int ry, int color)
{
	int s_x;
	int s_y;
	int x;
	int y;

	x = rx;
	s_x = 0;
	s_y = 0;
	while (++x < WIN_W)
	{
		y = ry;
		while (++y < WIN_H)
		{
			if (s_x < 70 && s_y < 70)
				img[y * WIN_W + x] = color;
			s_y++;
		}
		s_y = 0;
		s_x++;
	}
}

void		draw_rooms(t_mlx *mlx, t_info *info)
{
	t_room	*tmp;
	int		i;

	tmp = info->room;
	while (tmp)
	{
		i = 0;
		while (tmp->links[i])
		{
			if (!tmp->links[i]->visited)
				draw_line(mlx->img.img, *tmp, *tmp->links[i]);
			i++;
		}
		if (tmp->start)
			draw_room(mlx->img.img, tmp->x, tmp->y, 0x8C5226);
		else if (tmp->end)
			draw_room(mlx->img.img, tmp->x, tmp->y, 0xBA966B);
		else
			draw_room(mlx->img.img, tmp->x, tmp->y, 0x6D5D47);
		tmp->visited = 1;
		tmp = tmp->next;
	}
	tmp = info->room;
	while ((tmp = tmp->next))
		tmp->visited = 0;
}
