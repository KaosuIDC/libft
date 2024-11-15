/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:05:04 by sudelory          #+#    #+#             */
/*   Updated: 2024/11/15 13:05:15 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_l;
	size_t	src_l;

	i = 0;
	dest_l = 0;
	src_l = 0;
	while (dest_l < size && dst[dest_l])
		dest_l++;
	while (src[src_l])
		src_l++;
	if (dest_l >= size)
		return (size + src_l);
	while (i < size - dest_l - 1 && src[i])
	{
		dst[dest_l + i] = src[i];
		i++;
	}
	if (dest_l + i < size)
		dst[dest_l + i] = '\0';
	return (dest_l + src_l);
}
