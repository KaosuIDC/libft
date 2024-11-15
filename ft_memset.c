/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:30:44 by sudelory          #+#    #+#             */
/*   Updated: 2024/11/15 16:24:09 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sr;

	sr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		sr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
