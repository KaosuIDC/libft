/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:00:29 by sudelory          #+#    #+#             */
/*   Updated: 2024/11/26 17:35:41 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	get_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*if_int_min(void)
{
	int		i;
	char	*for_min;
	char	*to_copy;

	i = 0;
	to_copy = "-2147483648";
	for_min = malloc(12);
	if (!for_min)
		return (NULL);
	while (to_copy[i])
	{
		for_min[i] = to_copy[i];
		i++;
	}
	for_min[i] = '\0';
	return (for_min);
}

static char	*if_inf_to_zero(int n)
{
	char			*str;
	unsigned int	len;

	len = get_len(n);
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	n = -n;
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char				*str;
	unsigned int		len;

	len = get_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == INT_MIN)
	{
		free(str);
		return (if_int_min());
	}
	if (n < 0)
	{
		free(str);
		return (if_inf_to_zero(n));
	}
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
