#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t	i;

	i = 0;
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	while (i < nmemb * size)
	{
		temp[i] = '\0';
		i++;
	}
	return (temp);
}
