/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:50:12 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/19 16:40:30 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_rooms(t_info *info)
{
	t_room	*tmp;
	int		i;

	tmp = info->room;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_room	*get_room(t_info *info, char *s)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		if (ft_strequ(s, tmp->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room	*get_ending_room(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		if (tmp->end)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		ft_count_links(t_room *room)
{
	int		i;

	i = 0;
	if (!room)
		return (0);
	while (room->links[i])
		i++;
	return (i);
}

int		ft_size_path(t_info *info)
{
	int i;

	i = 0;
	while (info->path[i])
		i++;
	return (i);
}
