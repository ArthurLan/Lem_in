/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:52:52 by afrangio          #+#    #+#             */
/*   Updated: 2018/04/20 17:27:47 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTFT_H
# define LISTFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <wchar.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef t_list	t_stack;

void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t len);
t_stack			*ft_stacknew(void const *content, size_t len);
void			ft_stackpush(t_stack **stack, void *content, size_t len);
t_stack			*ft_stackpop(t_stack **stack);

#endif
