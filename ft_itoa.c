#include "libft.h"

char    *ft_itoa(int n)
{
	int     len = ft_strlen(n);
	char    *str = (char *)malloc(len + 1);
	unsigned int num = (n < 0) ? -n : n;

	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
