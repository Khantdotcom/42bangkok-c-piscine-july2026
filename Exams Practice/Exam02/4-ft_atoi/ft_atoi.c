/*
** ft_atoi - converts a string to an integer, matching libc atoi() behavior.
**
** Three-stage pipeline:
**
**   Stage 1 - Skip leading whitespace.
**     Whitespace = space (32) and control characters 9-13:
**     9='\t', 10='\n', 11='\v', 12='\f', 13='\r'.
**     Using the ASCII range avoids including <ctype.h>.
**
**   Stage 2 - Parse sign(s).
**     Consume all consecutive '+' and '-' characters.
**     Each '-' flips the sign: sign *= -1.
**     e.g. "--5" -> two flips -> sign=+1 -> +5
**          "-+5" -> one flip  -> sign=-1 -> -5
**
**   Stage 3 - Accumulate digits.
**     Standard positional-notation conversion:
**       res = res * 10 + (digit_char - '0')
**     Stop at the first non-digit character.
**     e.g. "42abc" -> 42 (stops at 'a').
**
** Edge cases:
**   - "   -42"  -> skip spaces, sign=-1, res=42 -> -42. Correct.
**   - "0"       -> loop runs once, res=0, sign=1 -> 0. Correct.
**   - ""        -> all loops don't fire, returns 0. Correct.
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	/* Stage 1: skip whitespace (space + ASCII 9-13) */
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	/* Stage 2: consume sign characters, flip on each '-' */
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	/* Stage 3: convert digit characters to integer */
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0'); /* shift left one decimal, add digit */
		i++;
	}
	return (res * sign);
}
