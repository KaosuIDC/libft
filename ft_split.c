/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:00:05 by sudelory          #+#    #+#             */
/*   Updated: 2024/11/26 20:10:25 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *src, int n)
{
	int		i;
	char	*dest;

	dest = ft_calloc(sizeof(char), (n + 1));
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
	return (dest);
}

static int	count_substrings(const char *s, char c)
{
	int	count;
	int	in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (*s != c && !in_substring)
		{
			in_substring = 1;
			count++;
		}
		else if (*s == c)
		{
			in_substring = 0;
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		start;
	int		end;
	int		i;

	buffer = ft_calloc(sizeof(char *), (count_substrings(s, c) + 1));
	if (!buffer || !s)
		return (NULL);
	start = 0;
	end = 0;
	i = 0;
	while (s[end])
	{
		if (s[end] == c)
		{
			if (end > start)
				buffer[i++] = ft_strndup(s + start, end - start);
			start = end + 1;
		}
		end += 1;
	}
	if (end > start)
		buffer[i++] = ft_strndup(s + start, end - start);
	return (buffer);
}
