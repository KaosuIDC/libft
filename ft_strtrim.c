/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:34:19 by sudelory          #+#    #+#             */
/*   Updated: 2024/11/19 19:01:20 by sudelory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*str_begin(char *s1, char *to_trim)
{
	size_t	i;
	size_t	j;
	int		trim;

	i = 0;
	trim = 0;
	while (s1[i])
	{
		j = 0;
		while (to_trim[j])
		{
			if (s1[i] == to_trim[j])
			{
				trim++;
				i++;
				j -= 1;
			}
			j++;
		}
		if (to_trim[j] == '\0')
			return (trim);
	}
	return (trim);
}

int	*str_end(char *s1, char *to_trim)
{
	size_t	i;
	size_t	j;
	int		trim;
}

char	*ft_strtrim(char const *s1, char const *set)
{

}