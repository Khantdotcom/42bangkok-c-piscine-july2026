unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	rev;
	int				bit;

	rev = 0;
	bit = 8;
	while (bit--)
	{
		rev = (rev << 1) | (octet & 1);
		octet >>= 1;
	}
	return (rev);
}
