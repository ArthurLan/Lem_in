/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_through.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 13:05:37 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/17 16:29:58 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		start_available(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		if (tmp->start == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		end_available(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		if (tmp->end == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		startend_available(t_info *info)
{
	return ((start_available(info) && end_available(info)));
}

int		check_room_duplicates(t_info *info, char *name)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		if (ft_strequ(name, tmp->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
