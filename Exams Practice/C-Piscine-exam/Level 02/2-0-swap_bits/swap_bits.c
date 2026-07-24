/*
** swap_bits - swaps the high nibble (upper 4 bits) with the
**             low nibble (lower 4 bits) of a byte.
**
** e.g.  0b01000001  ->  0b00010100
**         0100|0001      0001|0100
**
** One-liner trick:
**   octet >> 4   -> moves the high nibble into the low nibble position
**                   (upper bits become 0 due to unsigned shift).
**   octet << 4   -> moves the low nibble into the high nibble position
**                   (lower bits become 0, but since result is cast back
**                   to unsigned char, only the low 8 bits are kept).
**   OR them      -> combines both halves into the final swapped byte.
**
** No loop needed: bitwise shifts + OR handle it in a single expression.
*/
unsigned char	swap_bits(unsigned char octet)
{
	/* Right-shift brings high nibble down; left-shift raises low nibble up */
	return ((octet >> 4) | (octet << 4));
}
