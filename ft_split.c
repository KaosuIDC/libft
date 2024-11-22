/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:00:05 by sudelory          #+#    #+#             */
/*   Updated: 2024/11/19 13:23:19 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *src, int n)
{
	int		i;
	char	*dest;

	dest = malloc(n + 1);
	if (!dest)
	{
		return (NULL);
	}
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		start;
	int		end;
	int		len;
	int		i;

	len = ft_strlen(s);
	buffer = malloc(sizeof(char *) * (len + 1));
	if (!s || !buffer)
		return (NULL);
	start = 0;
	end = 0;
	i = 0;
	while (end <= len)
	{
		if (s[end] == 0 || s[end] == c)
		{
			if (end > start)
				buffer[i++] = ft_strndup(s + start, end - start);
			start = end + 1;
		}
		end += 1;
	}
	buffer[i] = 0;
	return (buffer);
}
