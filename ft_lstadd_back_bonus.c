/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:02:13 by sudelory          #+#    #+#             */
/*   Updated: 2024/11/28 05:41:52 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*finish;

	if (lst && new)
	{
		if (*lst)
		{
			finish = ft_lstlast(*lst);
			finish->next = new;
		}
		else
			*lst = new;
	}
}
