/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:00:05 by sudelory          #+#    #+#             */
/*   Updated: 2024/11/27 22:02:12 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	free_buffer(char **buffer, int i)
{
	while (i > 0)
		free(buffer[--i]);
	free(buffer);
}

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

static char	**split_strings(char const *s, char c, char **buffer)
{
	int		start;
	int		end;
	int		i;

	start = 0;
	end = 0;
	i = 0;
	while (1)
	{
		if (s[end] == c || s[end] == '\0')
		{
			if (end > start)
			{
				buffer[i] = ft_strndup(s + start, end - start);
				if (!buffer[i++])
					return (free_buffer(buffer, i - 1), NULL);
			}
			start = end + 1;
		}
		if (s[end++] == '\0')
			return (buffer);
	}
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;

	if (!s)
		return (NULL);
	buffer = ft_calloc(sizeof(char *), (count_substrings(s, c) + 1));
	if (!buffer)
		return (NULL);
	return (split_strings(s, c, buffer));
}
