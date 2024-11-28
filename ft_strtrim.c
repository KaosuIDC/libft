/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:34:19 by sudelory          #+#    #+#             */
/*   Updated: 2024/11/28 02:05:57 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_begin(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (set[j] == s1[i])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (i);
}

static int	str_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (set[j] && i > 0)
	{
		if (set[j] == s1[i])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	i2;
	char	*newstr;

	if (s1 == NULL && set == NULL)
		return (NULL);
	i = str_begin(s1, set);
	j = str_end(s1, set) + 1;
	if (i == ft_strlen(s1))
		newstr = malloc(1);
	else
		newstr = malloc((j - i) + 1);
	if (!newstr)
		return (NULL);
	i2 = 0;
	while (i < j)
	{
		newstr[i2] = s1[i];
		i2++;
		i++;
	}
	newstr[i2] = '\0';
	return (newstr);
}
