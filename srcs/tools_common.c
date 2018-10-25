/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 12:28:55 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/16 17:59:12 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_saveline(t_info *info)
{
	int newsize;

	if (!info->file)
	{
		info->file = ft_memalloc(sizeof(char) * (ft_strlen(info->buff) + 2));
		if (!info->file)
			ft_throw_error(0, info);
	}
	else
	{
		newsize = sizeof(char) * ft_strlen(info->file) + ft_strlen(info->buff);
		info->file = ft_realloc(info->file, newsize + sizeof(char) * 2);
		if (!info->file)
			ft_throw_error(0, info);
	}
	ft_strcat(info->file, info->buff);
	ft_strcat(info->file, "\n");
}

void	free_charofchar(char **table)
{
	int i;

	i = 0;
	if (table)
	{
		while (table[i])
		{
			ft_strdel(&table[i]);
			i++;
		}
		free(table);
	}
	table = NULL;
}
