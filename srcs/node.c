/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:07:32 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/26 12:04:33 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*create_room(char *name, int x, int y)
{
	t_room *node;

	if (!(node = ft_memalloc(sizeof(t_room))))
		return (NULL);
	else
	{
		node->name = name;
		node->next = NULL;
		node->x = x;
		node->y = y;
		node->links = ft_memalloc(sizeof(t_room) * 2);
		if (!node->links)
			return (NULL);
	}
	return (node);
}

void		add_room(t_room **begin_node, char *name, int x, int y)
{
	t_room *tmp;

	tmp = *begin_node;
	if (!*begin_node)
		*begin_node = create_room(name, x, y);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_room(name, x, y);
	}
}
