/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:00:29 by sudelory          #+#    #+#             */
/*   Updated: 2024/11/28 05:39:49 by sudelory         ###   ########.fr       */
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

static char	*if_inf_to_zero(char *str, int n, int len)
{
	n = -n;
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
	char			*str;
	unsigned int	len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = get_len(n);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		return (if_inf_to_zero(str, n, len));
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
