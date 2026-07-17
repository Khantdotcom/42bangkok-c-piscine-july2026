#include <stdlib.h>

/* Helper function to calculate the length of the needed string */
static int	get_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1; /* Accounts for '0' or the negative sign '-' */
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	long	n;
	int		len;

	n = nbr;
	len = get_len(n);
	
	/* Allocate memory for the string + 1 for the null terminator */
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
		
	str[len] = '\0';
	
	/* Handle the special case of 0 */
	if (n == 0)
		str[0] = '0';
		
	/* Handle negative numbers */
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	
	/* Populate the string from right to left */
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	
	return (str);
}