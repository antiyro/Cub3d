/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouhada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:42:46 by nbouhada          #+#    #+#             */
/*   Updated: 2020/11/23 15:37:17 by nbouhada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!lst || !*lst || !del)
		return ;
	tmp1 = *lst;
	tmp2 = *lst;
	while (tmp2)
	{
		tmp1 = tmp1->next;
		ft_lstdelone(tmp2, del);
		tmp2 = tmp1;
	}
	*lst = NULL;
}
