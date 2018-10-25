/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:21:31 by afrangio          #+#    #+#             */
/*   Updated: 2017/11/22 18:48:20 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *copy;
	t_list *ret;

	if (!lst)
		return (NULL);
	copy = f(lst);
	ret = copy;
	lst = lst->next;
	while (lst)
	{
		copy->next = f(lst);
		copy = copy->next;
		lst = lst->next;
	}
	return (ret);
}
