/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 12:01:54 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/19 20:03:25 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_throw_error(int error, t_info *info)
{
	ft_strdel(&info->file);
	ft_strdel(&info->buff);
	clean(info);
	free(info);
	ft_putendl_fd("Error", 2);
	exit(error);
}

void	ft_throw_error_coc(int error, t_info *info)
{
	free_charofchar(info->split);
	ft_throw_error(error, info);
}
