/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:38:26 by sudelory          #+#    #+#             */
/*   Updated: 2024/11/18 13:35:29 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*extract;
	size_t	i;
	size_t	length;

	i = 0;
	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start >= length)
		return (ft_strdup(""));
	if (len > length - start)
		len = length - start;
	extract = malloc(sizeof(char) * (len + 1));
	if (!extract)
		return (NULL);
	while (i < len)
	{
		extract[i] = s[start + i];
		i++;
	}
	extract[i] = '\0';
	return (extract);
}
