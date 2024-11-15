/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:13:18 by sudelory          #+#    #+#             */
/*   Updated: 2024/11/15 16:23:29 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*sf;
	const unsigned char	*sd;

	i = 0;
	sf = (const unsigned char *)s1;
	sd = (const unsigned char *)s2;
	while (i < n)
	{
		if (sf[i] != sd[i])
			return (sf[i] - sd[i]);
		i++;
	}
	return (0);
}
