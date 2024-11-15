/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:47:26 by sudelory          #+#    #+#             */
/*   Updated: 2024/11/15 16:30:15 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *strs)
{
	int	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
}

char	*ft_newstr(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i != size)
	{
		len = len + ft_strlen(strs[i]) + ft_strlen(sep);
		i++;
	}
	len -= ft_strlen(sep);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (NULL);
	dest[0] = 0;
	return (dest);
}

char	*ft_strcat(char *dest, char *sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (sep[j])
	{
		dest[i] = sep[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;

	i = 0;
	if (size <= 0)
	{
		dest = malloc(sizeof(char));
		dest[0] = '\0';
		return (dest);
	}
	dest = ft_newstr(size, strs, sep);
	if (!dest)
		return (NULL);
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i < size - 1)
			dest = ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}
