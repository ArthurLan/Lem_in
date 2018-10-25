/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:40:49 by afrangio          #+#    #+#             */
/*   Updated: 2017/11/22 18:48:18 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst)
		return ;
	if (del)
		del((*alst)->content, (*alst)->content_size);
	if ((*alst)->next)
		ft_lstdel(&((*alst)->next), *del);
	ft_memdel((void**)(alst));
}
