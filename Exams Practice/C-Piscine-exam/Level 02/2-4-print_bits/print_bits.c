#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int			bit;
	char	c;

	bit = 7;
	while (bit >= 0)
	{
		c = ((octet >> bit) & 1) + '0';
		write(1, &c, 1);
		bit--;
	}
}
