/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 23:41:45 by afrangio          #+#    #+#             */
/*   Updated: 2017/11/23 01:32:16 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stackpop(t_stack **stack)
{
	t_stack *ret;

	if (!stack || !*stack)
		return (NULL);
	ret = *stack;
	*stack = (*stack)->next;
	ret->next = NULL;
	return (ret);
}
