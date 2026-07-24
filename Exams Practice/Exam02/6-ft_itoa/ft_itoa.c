#include <stdlib.h>

/*
** count_digits - counts how many characters the string representation needs.
**
**   Negative number: one extra char for the '-' sign.
**   Always at least 1 (for "0" or any single-digit number).
**   Divides by 10 repeatedly to count decimal digits.
**
** Why use long n instead of int?
**   INT_MIN = -2147483648. Negating it as int overflows (UB in C).
**   Promoting to long first makes -(-2147483648) = 2147483648 safe.
*/
static int	count_digits(long n)
{
	int	len;

	len = 1; /* minimum 1 digit */
	if (n < 0)
	{
		len++; /* account for '-' sign character */
		n = -n; /* work with absolute value */
	}
	while (n >= 10) /* count additional digits beyond the first */
	{
		n /= 10;
		len++;
	}
	return (len);
}

/*
** ft_itoa - converts int to a heap-allocated null-terminated string.
**
** Fill-from-the-right technique:
**   We know the total length upfront (count_digits), so we can write
**   digits directly into their correct positions from the end backwards.
**   res[--len] places the least-significant digit first (rightmost),
**   then each /= 10 strips it, revealing the next digit.
**
** Special case - n == 0:
**   The while(n > 0) loop never fires for 0. We explicitly set res[0]='0'.
**   This happens BEFORE the n<0 check, so if n were -0 (impossible for int)
**   it wouldn't overwrite; but for n==0 it sets the one character needed.
**
** Negative number handling:
**   Negate n to work with absolute value, fill digits right-to-left,
**   then res[0] = '-' is set during the n<0 block at len index 0.
**   The fill loop stops at len==1 (the '-' slot), leaving res[0]='-'. Correct.
**
** Ownership: caller must free() the returned pointer.
*/
char	*ft_itoa(int nbr)
{
	long	n;
	int		len;
	char	*res;

	n = nbr;              /* promote to long to safely handle INT_MIN */
	len = count_digits(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	res[len] = '\0';      /* null-terminate at the computed end */
	if (n == 0)
		res[0] = '0';     /* special case: loop below won't fire for 0 */
	if (n < 0)
	{
		res[0] = '-';     /* place sign at index 0 */
		n = -n;           /* work with positive value for digit extraction */
	}
	/* Fill digits right-to-left: least significant digit goes in last */
	while (n > 0)
	{
		res[--len] = (n % 10) + '0'; /* extract last digit, convert to char */
		n /= 10;                     /* remove extracted digit */
	}
	return (res);
}
