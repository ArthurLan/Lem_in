/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:50:04 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/19 20:05:42 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_check_link_exists(t_room *room, char *connection)
{
	int i;

	i = 0;
	while ((room->links[i]))
	{
		if (room->links[i]->name)
			if (ft_strequ((room->links[i])->name, connection))
				return (1);
		i++;
	}
	return (0);
}

void		ft_assignlink(t_room *room, t_room *link)
{
	int i;
	int	previous;
	int	next;

	i = 0;
	while (room->links[i])
		i++;
	previous = sizeof(t_room) * (i);
	next = sizeof(t_room) * (i + 1);
	room->links = ft_memrealloc(room->links, previous, next);
	room->links[i] = link;
}

void		ft_addlink(t_info *info, char *room, char *link)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		if (ft_strequ(tmp->name, room))
		{
			if (!ft_check_link_exists(tmp, link))
				ft_assignlink(tmp, get_room(info, link));
		}
		tmp = tmp->next;
	}
}

static int	ft_check_room_exists(t_info *info, char *name, int flag)
{
	t_room *tmp;

	if (flag == 1)
	{
		tmp = info->room;
		while (tmp)
		{
			if (ft_strequ(tmp->name, name))
				return (1);
			tmp = tmp->next;
		}
		return (0);
	}
	else
	{
		ft_addlink(info, info->split[0], info->split[1]);
		ft_addlink(info, info->split[1], info->split[0]);
		free_charofchar(info->split);
		return (1);
	}
	return (0);
}

int			ft_islink(t_info *info)
{
	int		i;

	if (ft_strchr(info->buff, ' '))
		return (0);
	info->split = ft_strsplit(info->buff, '-');
	i = 0;
	while (info->split[i])
		i++;
	if (i != 2)
	{
		free_charofchar(info->split);
		return (0);
	}
	if (ft_strequ(info->split[0], info->split[1]))
	{
		free_charofchar(info->split);
		return (-1);
	}
	if (!ft_check_room_exists(info, info->split[0], 1) || \
		!ft_check_room_exists(info, info->split[1], 1))
	{
		free_charofchar(info->split);
		return (-1);
	}
	return (ft_check_room_exists(info, NULL, 2));
}
