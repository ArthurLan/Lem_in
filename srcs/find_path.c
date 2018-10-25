/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:15:09 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/24 09:22:45 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		transform(t_info *info, int size)
{
	t_room *tmp;
	t_room *end;

	if (info->path && size > 0)
	{
		tmp = info->path[size];
		if (tmp->start)
		{
			ft_set_path(info, &tmp, &end);
			ft_putendl(info->file);
			ft_print_lems(info, end, tmp);
		}
		else
		{
			free(info->path);
			ft_throw_error(E_NO_PATH, info);
		}
	}
	else
	{
		free(info->path);
		ft_throw_error(E_NO_PATH, info);
	}
}

static int	find_path_bis(t_info *info, int *size, int i, int *nb_links)
{
	if (!(info->path[i]->links[*nb_links]->visited))
	{
		*size = ft_size_path(info);
		info->path[*size] = (info->path[i])->links[*nb_links];
		(info->path[*size])->visited = 1;
		info->path[*size]->next_room = info->path[i];
	}
	if ((info->path[*size])->start)
		return (0);
	(*nb_links)++;
	return (1);
}

void		find_path(t_info *info, t_room *end)
{
	int nb_links;
	int i;
	int size;

	size = -1;
	info->path = ft_memalloc(sizeof(t_room*) * count_rooms(info) + 10);
	if (!info->path)
		ft_throw_error(0, info);
	info->path[0] = end;
	end->visited = 1;
	end->next_room = NULL;
	i = 0;
	while (info->path[i])
	{
		nb_links = 0;
		while (nb_links < ft_count_links(info->path[i]))
			if (!(find_path_bis(info, &size, i, &nb_links)))
				break ;
		if (size != -1 && (info->path[size])->start)
			break ;
		i++;
	}
	transform(info, size);
	free(info->path);
}
