/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:09:05 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/11 19:25:03 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	return (str);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;
	int		c[2];

	c[0] = -1;
	c[1] = -1;
	if (!s1 || !s2)
		return (NULL);
	str = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!str)
		return (NULL);
	while (s1[++c[0]])
		str[++c[1]] = s1[c[0]];
	c[0] = -1;
	while (s2[++c[0]])
		str[++c[1]] = s2[c[0]];
	free(s1);
	return (str);
}
