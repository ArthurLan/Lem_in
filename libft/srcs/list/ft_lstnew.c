/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 23:41:45 by afrangio          #+#    #+#             */
/*   Updated: 2017/11/22 20:58:29 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t len)
{
	t_list *liste;

	liste = (t_list*)ft_memalloc(sizeof(t_list) * len);
	if (!liste)
		return (NULL);
	liste->content = ft_memalloc(sizeof(void) * len);
	if (!liste->content)
		return (NULL);
	if (content)
	{
		liste->content_size = len;
		ft_memcpy(liste->content, content, len);
	}
	else
	{
		liste->content_size = 0;
		liste->content = NULL;
	}
	liste->next = NULL;
	return (liste);
}
