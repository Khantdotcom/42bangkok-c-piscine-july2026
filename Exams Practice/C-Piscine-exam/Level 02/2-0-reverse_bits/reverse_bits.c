/*
** reverse_bits - returns octet with its 8 bits in reversed order.
**
** e.g.  0b00100110  ->  0b01100100
**         bit 7 becomes bit 0, bit 0 becomes bit 7, etc.
**
** Trick: peel the LSB (least-significant bit) off the input and
**        glue it as the new MSB (most-significant bit) of the result.
**
**   octet & 1        -> isolates the current LSB (0 or 1)
**   rev << 1         -> shift result left to make room for next bit
**   | (octet & 1)    -> OR the LSB into the vacated position
**   octet >>= 1      -> discard processed bit, move to next one
**
** After 8 iterations, all bits have been peeled from octet and
** pushed (in reverse order) into rev.
**
** Why bit-- (post-decrement):
**   First iteration: bit is 8, condition true (non-zero), then bit=7.
**   Last iteration:  bit is 1, condition true, then bit=0.
**   After loop:      bit is 0, condition false -> exits. 8 total runs.
*/
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	rev;
	int				bit;

	rev = 0;
	bit = 8; /* 8 bits to process */
	while (bit--)
	{
		rev = (rev << 1) | (octet & 1); /* pull LSB of octet into MSB of rev */
		octet >>= 1;                    /* advance to next bit in octet */
	}
	return (rev);
}
