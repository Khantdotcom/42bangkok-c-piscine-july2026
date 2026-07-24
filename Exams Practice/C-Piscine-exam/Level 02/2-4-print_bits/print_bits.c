#include <unistd.h>

/*
** print_bits - prints a byte as an 8-character binary string.
**              No newline at end (subject requirement).
**
** e.g. print_bits(2) prints "00000010"
**      print_bits(255) prints "11111111"
**
** Trick: extract one bit at a time from MSB (bit 7) down to LSB (bit 0).
**
**   octet >> bit  -> shift the target bit down to position 0.
**   & 1           -> isolate that single bit (result is 0 or 1).
**   + '0'         -> convert 0/1 to ASCII '0'/'1'.
**
** Starting from bit=7 (most significant) ensures the output is
** printed in natural left-to-right binary order (MSB first).
**
** write() is used instead of printf() because the function signature
** allows only write, and it avoids any output buffering issues.
*/
void	print_bits(unsigned char octet)
{
	int		bit;
	char	c;

	bit = 7; /* start from the most-significant bit */
	while (bit >= 0)
	{
		/* Shift target bit to position 0, mask it, convert to '0'/'1' */
		c = ((octet >> bit) & 1) + '0';
		write(1, &c, 1);
		bit--;
	}
	/* No newline: subject explicitly says WITHOUT A NEWLINE AT THE END */
}
