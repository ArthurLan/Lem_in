/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:39:17 by alanter           #+#    #+#             */
/*   Updated: 2018/10/25 18:58:22 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "libft.h"
# include "lem_in.h"
# include <limits.h>
# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define WIN_W 1350
# define WIN_H 780

typedef struct		s_img
{
	void			*img_ptr;
	unsigned int	*img;
	char			*rand;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	struct s_info	*info;
	void			*mlx_ptr;
	void			*win;
	t_img			img;
	int				speed;
	int				menu;
}					t_mlx;

void			*window(t_info *info);
void			draw_str(t_mlx *mlx);
void			draw_back(t_img *img, int i);
void			draw_rooms(t_mlx *mlx, t_info *info);
void			ft_new_image(t_mlx *mlx);
void			calc_coord(t_info *info);
void			draw_ants(t_mlx *mlx, t_info *info);
void			move_ants(t_info *info);

#endif
