/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 12:22:51 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/17 16:30:00 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_isant_number(t_info *info)
{
	int i;

	i = 0;
	while (info->buff[i])
	{
		(info->buff[i] == '+') ? i++ : i;
		if (!ft_isdigit(info->buff[i]))
			return (0);
		i++;
	}
	if (ft_strlen(info->buff) > 11)
		return (0);
	else if (ft_atol(info->buff) > INT_MAX || ft_atol(info->buff) < INT_MIN)
		return (0);
	return (ft_atoi(info->buff));
}
