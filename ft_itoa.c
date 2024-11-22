#include <stdlib.h>

static int  get_num_len(int n)
{
	int len = (n <= 0) ? 1 : 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return len;
}

char    *ft_itoa(int n)
{
	int     len = get_num_len(n);
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
