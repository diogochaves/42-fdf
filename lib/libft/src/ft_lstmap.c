/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:32:14 by dchaves-          #+#    #+#             */
/*   Updated: 2021/09/14 20:32:14 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_cpy;
	t_list	*lst_start;

	lst_start = 0;
	while (lst)
	{
		lst_cpy = ft_lstnew(f(lst->content));
		if (!lst_cpy)
		{
			ft_lstclear(&lst_start, del);
			return (0);
		}
		ft_lstadd_back(&lst_start, lst_cpy);
		lst = lst->next;
	}
	return (lst_start);
}
