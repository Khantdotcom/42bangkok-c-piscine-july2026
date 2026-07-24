#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
** do_op - evaluates a simple arithmetic expression passed as 3 arguments:
**         argv[1] op argv[3],  where argv[2] is one of: + - * / %
**
** Why argc must equal 4:
**   argv[0]=program, argv[1]=left operand, argv[2]=operator, argv[3]=right.
**   Any other count is an error -> print only '\n' and exit.
**
** Operator parsing:
**   argv[2][1] != '\0' -> the operator string has more than one char,
**                         which is not a valid single-operator token.
**   argv[2][0] -> the actual operator character.
**
** Division and modulo edge case:
**   b == 0 -> division by zero is undefined behavior in C.
**   We guard it with a ternary and return 0 to avoid a crash.
**   The subject guarantees well-formed input, but this is good habit.
**
** Output via printf:
**   printf is allowed here per the subject (atoi + printf + write).
**   write is used for the mandatory trailing newline to avoid printf
**   buffering issues in a piped context.
**
** Requirement cases:
**   - argc != 4              -> '\n' only.
**   - Operator not in set   -> prints "0\n".
**   - Operator string > 1 char -> prints "0\n".
**   - Division/modulo by 0  -> prints "0\n".
*/
int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	res;

	if (argc != 4)
	{
		write(1, "\n", 1); /* wrong arg count: output newline and exit */
		return (0);
	}
	a = atoi(argv[1]); /* convert left operand string to int */
	b = atoi(argv[3]); /* convert right operand string to int */
	res = 0;
	/* Guard: operator must be exactly one character */
	if (argv[2][1] != '\0')
		printf("0");
	else if (argv[2][0] == '+')
		res = a + b;
	else if (argv[2][0] == '-')
		res = a - b;
	else if (argv[2][0] == '*')
		res = a * b;
	else if (argv[2][0] == '/')
		res = (b == 0) ? 0 : a / b; /* guard against division by zero */
	else if (argv[2][0] == '%')
		res = (b == 0) ? 0 : a % b; /* guard against modulo by zero */
	else
		printf("0"); /* unknown operator */
	/* Print result only when operator was a valid single-char symbol */
	if (argv[2][1] == '\0' && (argv[2][0] == '+' || argv[2][0] == '-'
			|| argv[2][0] == '*' || argv[2][0] == '/' || argv[2][0] == '%'))
		printf("%d", res);
	write(1, "\n", 1); /* always end with newline */
	return (0);
}
