/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_printants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 20:11:41 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/23 17:59:58 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_start(t_info *info, t_room *tmp)
{
	ft_putchar('L');
	ft_putnbr(info->ants - tmp->ant + 1);
	ft_putchar('-');
	ft_putstr(tmp->next_room->name);
	tmp->next_room->ant = info->ants - tmp->ant + 1;
	tmp->ant--;
}

void	ft_print_end(t_room *tmp)
{
	ft_putchar('L');
	ft_putnbr(tmp->ant);
	ft_putchar('-');
	ft_putstr(tmp->next_room->name);
	tmp->next_room->ant++;
	tmp->ant = 0;
}

void	ft_print_else(t_room *tmp)
{
	ft_putchar('L');
	ft_putnbr(tmp->ant);
	ft_putchar('-');
	ft_putstr(tmp->next_room->name);
	tmp->next_room->ant = tmp->ant;
	tmp->ant = 0;
}

void	ft_print_lems(t_info *info, t_room *end, t_room *tmp)
{
	while (end->ant != info->ants)
	{
		tmp = end->previous_room;
		while (tmp)
		{
			if (tmp->ant)
			{
				if (tmp->start)
					ft_print_start(info, tmp);
				else if (tmp->end)
					ft_print_end(tmp);
				else
					ft_print_else(tmp);
				if (tmp->previous_room && tmp->previous_room->ant)
					ft_putchar(' ');
			}
			tmp = tmp->previous_room;
		}
		ft_putchar('\n');
	}
}

void	ft_set_path(t_info *info, t_room **tmp, t_room **end)
{
	(*tmp)->ant = info->ants;
	while (!((*tmp)->end))
	{
		(*tmp)->next_room->previous_room = *tmp;
		*tmp = (*tmp)->next_room;
	}
	*end = *tmp;
}
