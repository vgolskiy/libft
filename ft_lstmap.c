/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <mskinner@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:46:09 by mskinner          #+#    #+#             */
/*   Updated: 2020/04/30 00:25:22 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *))
{
	t_list	*new;
	t_list	*res;

	if ((!lst) || (f == 00))
		return (00);
	res = 00;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (new->content == 00)
		{
			ft_lstclear(&res, del);
			return (res);
		}
		ft_lstadd_back(&res, new);
		lst = lst->next;
	}
	return (res);
}
