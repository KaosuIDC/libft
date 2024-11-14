#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	const unsigned char	*point;
	unsigned char	to_find;

	i = 0;
	point = (const unsigned char *)s;
	to_find = (unsigned char)c;

	while (i < n)
	{
		if (point[i] == to_find)
			return ((void *)&point[i]);
		i++;
	}
	return (0);
}
