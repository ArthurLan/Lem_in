/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:49:36 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/23 18:44:43 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_isnumber(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '+')
			i++;
		else if (s[i] == '-')
			i++;
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if (ft_strlen(s) > 11)
		return (0);
	else if (ft_atol(s) > INT_MAX || ft_atol(s) < INT_MIN)
		return (0);
	return (1);
}

int			ft_isvalid_room_name(char *s)
{
	int i;

	i = 0;
	if (s[i] == 'L')
		return (0);
	while (s[i])
	{
		if (!ft_isprint(s[i]) || s[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void		ft_setstart(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp->next)
		tmp = tmp->next;
	tmp->start = 1;
	info->start = 2;
}

void		ft_setend(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp->next)
		tmp = tmp->next;
	tmp->end = 1;
	info->end = 2;
}

int			ft_isroom(t_info *info)
{
	int		i;

	info->split = ft_strsplit(info->buff, ' ');
	i = 0;
	while (info->split[i])
		i++;
	if (i != 3)
	{
		free_charofchar(info->split);
		return (0);
	}
	if (!ft_isvalid_room_name(info->split[0]) || \
		!ft_isnumber(info->split[1]) || \
		!ft_isnumber(info->split[2]))
		ft_throw_error_coc(E_WRONG_ROOM_NAME, info);
	if (check_room_duplicates(info, info->split[0]))
		ft_throw_error_coc(E_DUPLICATE_ROOM, info);
	add_room(&info->room, ft_strdup(info->split[0]), ft_atoi(info->split[1]),
			ft_atoi(info->split[2]));
	(info->start == 1) ? ft_setstart(info) : 0;
	(info->end == 1) ? ft_setend(info) : 0;
	free_charofchar(info->split);
	return (1);
}
