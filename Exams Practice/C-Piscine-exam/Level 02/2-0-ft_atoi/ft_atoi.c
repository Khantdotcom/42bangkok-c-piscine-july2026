/*
** ft_atoi - converts a string to an integer, mirroring libc atoi().
**
** Pipeline:
**   1. Skip leading whitespace: space (32) and control chars 9-13
**      (\t \n \v \f \r). Using ASCII range avoids including <ctype.h>.
**   2. Parse sign: consume ALL consecutive '+'/'-' chars, flipping
**      sign *= -1 on each '-'. Multiple signs are allowed by the spec.
**      e.g. "--+5" -> sign flips twice -> +5.
**   3. Accumulate digits: res = res * 10 + digit converts ASCII to int
**      one digit at a time (positional notation). Stops at first
**      non-digit, so "42abc" correctly gives 42.
**
** Edge cases handled:
**   - Leading whitespace (any amount).
**   - Multiple sign chars.
**   - Non-numeric suffix -> parsing stops cleanly.
**   - "0" -> returns 0 (loop never fires, res stays 0, sign 1).
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	/* Step 1: skip whitespace (space + ASCII 9-13 = \t \n \v \f \r) */
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	/* Step 2: handle any number of sign characters */
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1; /* flip sign on each '-' */
		i++;
	}
	res = 0;
	/* Step 3: convert digit chars to integer value */
	while (str[i] >= '0' && str[i] <= '9')
	{
		/* Shift accumulated result left one decimal place, add new digit.
		   str[i] - '0' converts ASCII code to numeric value 0-9. */
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
