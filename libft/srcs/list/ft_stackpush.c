/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 23:41:45 by afrangio          #+#    #+#             */
/*   Updated: 2017/11/22 20:58:05 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackpush(t_stack **stack, void *content, size_t len)
{
	t_stack *new;

	new = ft_stacknew(content, len);
	new->next = *stack;
	*stack = new;
}
