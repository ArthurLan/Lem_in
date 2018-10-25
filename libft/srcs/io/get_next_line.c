/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:35:11 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/03 11:26:27 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char		*copy_until_backslash(char **suite)
{
	char	*tmpret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmpret = ft_memalloc(sizeof(char) * ft_strlen(*suite) + 2);
	if (!tmpret)
		return (NULL);
	while ((*suite)[i] != '\n' && (*suite)[i])
	{
		tmpret[i] = (*suite)[i];
		i++;
	}
	tmpret[i] = '\0';
	while ((*suite)[i + j])
	{
		(*suite)[j] = (*suite)[i + 1 + j];
		j++;
	}
	(*suite)[j] = '\0';
	return (tmpret);
}

static int		ft_read(char **suite, int fd, int lu)
{
	char	*tmp;
	int		realloc_size;

	tmp = ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	if (!tmp)
		return (-1);
	if (!ft_strstr(*suite, "\n"))
	{
		while ((lu = (read(fd, tmp, BUFF_SIZE))) > 0)
		{
			if (lu < 0)
				return (0);
			realloc_size = sizeof(char) * ft_strlen(*suite) + 1 + BUFF_SIZE;
			(*suite) ? *suite = ft_realloc(*suite, realloc_size) : 0;
			if (!*suite)
				return (0);
			ft_strncat(*suite, tmp, BUFF_SIZE);
			if (ft_strstr(tmp, "\n"))
				break ;
			ft_bzero(tmp, BUFF_SIZE);
		}
	}
	free(tmp);
	return (lu);
}

int				get_next_line(int fd, char **line)
{
	static char	*suite[OPEN_MAX];
	int			lu;

	if (fd < 0 || fd > OPEN_MAX)
		return (-1);
	if (!line)
		return (-1);
	if (!suite[fd])
		suite[fd] = ft_memalloc(sizeof(char) * BUFF_SIZE);
	if (!suite[fd])
		return (-1);
	lu = ft_read(&suite[fd], fd, 1);
	*line = copy_until_backslash(&suite[fd]);
	if (!*line)
		return (-1);
	if (ft_strlen(*line) || ft_strlen(suite[fd]) || lu > 0)
		lu = 1;
	else
		free(suite[fd]);
	return (lu);
}
