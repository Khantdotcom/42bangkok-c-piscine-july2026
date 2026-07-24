/*
** is_power_of_2 - returns 1 if n is a power of 2, 0 otherwise.
**
** Bit trick: a power of 2 has exactly ONE bit set in binary.
**   e.g. 1 = 0001,  2 = 0010,  4 = 0100,  8 = 1000
**
** Key identity:  n & (n - 1)
**   Subtracting 1 from a power of 2 flips the single set bit to 0
**   and sets all lower bits to 1.
**   e.g. 8 = 1000,  7 = 0111  ->  8 & 7 = 0000 == 0  -> is a power of 2
**        6 = 0110,  5 = 0101  ->  6 & 5 = 0100 != 0  -> not a power of 2
**
**   So (n & (n - 1)) == 0  is true if and only if n has exactly one bit set.
**
** Why special-case n == 0?
**   0 & (0 - 1) = 0 & 0xFFFFFFFF = 0, which would incorrectly return 1.
**   0 is NOT a power of 2 (no integer k satisfies 2^k = 0), so we
**   return 0 first.
**
** Why unsigned int?
**   Negative signed values could have the sign bit set, giving wrong
**   results. Using unsigned int ensures all bits are value bits.
**
** Complexity: O(1) - single bitwise AND, no loop needed.
*/
int	is_power_of_2(unsigned int n)
{
	if (n == 0)                   /* 0 is not a power of 2 */
		return (0);
	return ((n & (n - 1)) == 0);  /* true only when exactly one bit is set */
}
