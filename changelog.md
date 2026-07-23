# C03 / C04 / C05 Comparison Changelog

Compared against the reference solutions in `/Users/khant.h/Downloads/42-C-piscine-main 2`.

Note: `norminette` was not available in the current shell, so Norm findings below are based on direct source inspection.

## C03

### ex00 - `ft_strcmp.c`
Status: Incorrect. Your file is empty.

**The Fix**
```c
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
```

**The Mistake**
There is no implementation, so the exercise cannot compile or be evaluated.

**The Concept**
`strcmp` walks both strings until the first mismatch or `\0`, then returns the difference between those two bytes.

### ex01 - `ft_strncmp.c`
Status: Incorrect. The file contains `ft_strcat`-style code instead of `ft_strncmp`, and it uses an undeclared variable `n`.

**The Fix**
Replace the current function block with:
```c
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		if (i < n - 1)
			i++;
		else
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
```
Also remove the unused helper/test code:
```c
-#include <unistd.h>
-void	print_char(char *s)
-// int	main(void)
```

**The Mistake**
This is a copy/paste mix-up: the file name and expected prototype are for bounded string comparison, but the code is trying to concatenate strings.

**The Concept**
`strncmp` compares at most `n` characters. It does not build a new string or append anything.

### ex02 - `ft_strcat.c`
Status: Logically correct, but not Norm-clean.

**The Fix**
Remove the unused include and helper/test code, and fix spacing:
```c
-#include <unistd.h>

-while(dest[i])
+while (dest[i])

-while(src[j])
+while (src[j])

-void	print_char(char *s)
-// int	main(void)
```

**The Mistake**
The function itself works, but extra debug code and spacing issues will be flagged during evaluation.

**The Concept**
For Piscine submissions, correctness is not enough. The delivered file also has to match the required prototype and formatting rules.

### ex03 - `ft_strncat.c`
Status: Incorrect. Your file is empty.

**The Fix**
```c
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
```

**The Mistake**
There is no implementation, so nothing can be tested.

**The Concept**
`strncat` appends at most `nb` characters and then writes a final `\0` terminator.

### ex04 - `ft_strstr.c`
Status: Incorrect. Wrong function name, incomplete search logic, local declaration inside the loop body, and no return at the end.

**The Fix**
Delete `ft_len`, rename the function, and replace the broken body with a real substring search:
```c
-int	ft_len(char *s)
-{
-	...
-}
-char	*strstr(char *str, char *to_find)
+char	*ft_strstr(char *str, char *to_find)
 {
-	int	 i;
-	int	len;
+	unsigned int	i;
+	unsigned int	j;

-	len = ft_len(to_find);
 	i = 0;
-	while(str[i])
+	while (str[i] != '\0')
 	{
-		int	j;
-
-		j = 0;
-		while(to_find[j]) 
-			if(to_find[j] == str[i])
-			{
-				continue;
-			}
+		j = 0;
+		if (to_find[j] == '\0')
+			return (&str[i]);
+		if (str[i] == to_find[0])
+		{
+			while (to_find[j] != '\0')
+			{
+				if (str[i + j] != to_find[j])
+					break ;
+				j++;
+				if (to_find[j] == '\0')
+					return (&str[i]);
+			}
+		}
+		i++;
 	}
+	return (0);
 }
```

**The Mistake**
The current loop never actually compares a candidate substring correctly. `continue` here just traps execution instead of advancing the search.

**The Concept**
`strstr` needs a nested comparison: one index scans possible starting positions, and another checks whether the whole `to_find` string matches from that point.

### ex05 - `ft_strlcat.c`
No comparison: there is no matching reference file in the provided reference tree.

## C04

### ex00 - `ft_strlen.c`
Status: Logically correct, but not Norm-clean.

**The Fix**
Remove the unnecessary include, add the usual 42 header block at the top, and fix spacing:
```c
-#include <unistd.h>

-while(str[i])
+while (str[i])
```

**The Mistake**
`ft_strlen` does not use `write`, so the include is leftover debug scaffolding.

**The Concept**
Keep each submission file minimal: only the required function, required includes, and Norm-compliant formatting.

### ex01 - `ft_putstr.c`
Status: Logically correct, but not Norm-clean.

**The Fix**
Add the usual 42 header block and fix spacing around `while` and `write`:
```c
-while(str[i])
+while (str[i])

-		write(1,&str[i],1);
+		write(1, &str[i], 1);
```

**The Mistake**
The output is fine, but the formatting is tighter than Norm expects.

**The Concept**
Norminette checks layout and spacing, not just behavior. A correct result can still fail the project if style rules are broken.

### ex02 - `ft_putnbr.c`
Status: Incorrect for `INT_MIN`, and not Norm-clean.

**The Fix**
Replace the function body with an `INT_MIN`-safe version and clean up spacing:
```c
void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb <= 9)
	{
		c = nb + '0';
		ft_putchar(c);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
```

**The Mistake**
Negating `-2147483648` overflows a signed `int`, so your current `nb *= -1;` breaks on the smallest possible integer.

**The Concept**
Two's-complement integers are asymmetric: `INT_MIN` has no positive counterpart inside `int`, so it needs special handling.

### ex03 - `ft_atoi.c`
Status: Incorrect. The sign loop is mis-braced, so `'+'` can cause an infinite loop. Formatting also fails Norm.

**The Fix**
Keep the structure, but fix the sign loop and indentation:
```c
-    while (str[i] == '-' || str[i] == '+')
-    {
-        if (str[i] == '-')
-        {
-            sign = -sign; 
-        i++;
-    }}
+    while (str[i] == '-' || str[i] == '+')
+    {
+        if (str[i] == '-')
+            sign = -sign;
+        i++;
+    }
```
Then add the standard 42 header and re-indent the file with tabs.

**The Mistake**
`i++` is currently inside the `if (str[i] == '-')` block. When the current sign is `'+'`, `i` never advances.

**The Concept**
With parsers, every accepted character class must advance the cursor. If the index does not move, the loop never consumes input.

### ex04 - `ft_putnbr_base.c`
No comparison: there is no matching reference file in the provided reference tree.

### ex05 - `ft_atoi_base.c`
No comparison: there is no matching reference file in the provided reference tree.

## C05

### ex00 - `ft_iterative_factorial.c`
Status: Incorrect for `0`, and not Norm-clean.

**The Fix**
Declare variables before statements, remove debug includes, and handle `0!` correctly:
```c
-#include <unistd.h>
-#include <stdio.h>

 int	ft_iterative_factorial(int nb)
 {
-	if	(nb <= 0)
-	{
-		return(0);
-	}
 	int	result;

+	if (nb < 0)
+		return (0);
+	if (nb == 0)
+		return (1);
 	result = 1;
 
-	while(nb > 1){
+	while (nb > 1)
+	{
 		result *= nb;
 		nb--;
 	}
-	return result;
+	return (result);
 }
```

**The Mistake**
`0!` is defined as `1`, not `0`. The early return currently folds zero together with negative inputs.

**The Concept**
Factorial has two special cases: negative inputs return `0` for this exercise, and `0!` is the multiplicative identity `1`.

### ex01 - `ft_recursive_factorial.c`
Status: Incorrect. It calls the wrong function and returns the wrong value for `0`.

**The Fix**
```c
-#include <unistd.h>
-#include <stdio.h>

 int	ft_recursive_factorial(int	nb)
 {
-	if (nb <= 0)
-	{
-		return (0);
-	}
+	if (nb < 0)
+		return (0);
+	if (nb == 0)
+		return (1);
 	if (nb == 1)
-	{
 		return (1);
-	}
-	return (nb * ft_iterative_factorial(nb-1));
+	return (nb * ft_recursive_factorial(nb - 1));
 }
```

**The Mistake**
This is another copy/paste error: the recursive function calls the iterative one, and its base case treats `0` incorrectly.

**The Concept**
Recursive functions must reduce the problem by calling themselves with a smaller argument until a correct base case is reached.

### ex02 - `ft_iterative_power.c`
Status: Incorrect. The current loop never decrements or counts upward, so it never terminates.

**The Fix**
```c
-#include <unistd.h>
-
 int	ft_iterative_power(int nb, int power)
 {
 	int	i;
+	int	ans;
 
 	i = 1;
+	ans = 1;
+	if (power < 0)
+		return (0);
 	if (power == 0)
-	{
 		return (1);
-	}
-	while(power > 0)
+	while (i <= power)
 	{
-		i *= nb;
+		ans *= nb;
+		i++;
 	}
-	return i;
+	return (ans);
 
 }
```

**The Mistake**
You are updating the accumulator variable `i` instead of using it as a loop counter, and the loop condition never changes.

**The Concept**
An iterative power function needs two roles: a counter that moves toward termination, and an accumulator that stores the product.

### ex03 - `ft_recursive_power.c`
Status: Incorrect. It is missing negative-power handling and still contains a `main` function.

**The Fix**
```c
 int	ft_recursive_power(int nb, int power)
 {
-	if (power == 0){
+	if (power < 0)
+		return (0);
+	if (power == 0)
+	{
 		return (1);
 	}
-	return nb * ft_recursive_power(nb, power-1);
+	return (nb * ft_recursive_power(nb, power - 1));
 }
-
-int	main(void)
-{
-	if(ft_recursive_power(0,0) == 1)
-	{
-		write(1,"Lee",3);
-	}
-}
```

**The Mistake**
For negative powers, the recursion never reaches `0`, so it runs forever until stack overflow. The `main` function is also forbidden in the submission file.

**The Concept**
Recursive code needs a base case for every accepted input class. If one class has no base case, the recursion is unbounded.

### ex04 - `ft_fibonacci.c`
Status: Logically correct, but not Norm-clean.

**The Fix**
Remove the unnecessary include and clean up operator spacing:
```c
-#include <unistd.h>

-	return ft_fibonacci(index-1) + ft_fibonacci(index-2);
+	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
```

**The Mistake**
The recursion is fine; the problems are leftover include noise and formatting.

**The Concept**
Even when recursion is correct, small style details still matter in Piscine grading.

### ex05 - `ft_sqrt.c`
Status: Logically correct, but not Norm-clean.

**The Fix**
Add the usual 42 header, switch to tab-based indentation, and remove the inline comment:
```c
-int ft_sqrt(int nb)
+int	ft_sqrt(int nb)

-    // A negative number or 0 does not have a positive integer square root
```

**The Mistake**
The algorithm is fine, but the file formatting does not match the rest of your Piscine submissions.

**The Concept**
Norminette enforces a uniform house style. Comments and spacing that are fine in normal C projects can still be rejected here.

### ex06 - `ft_is_prime.c`
Status: Incorrect for `1`, and not Norm-clean.

**The Fix**
```c
-#include <unistd.h>
-
 int	ft_is_prime(int nb)
 {
-	if (nb <= 0)
+	int	i;
+
+	if (nb <= 1)
 	{
 		return (0);
 	}
-	int i;
 
 	i = 2;
-	while(i <= nb/2)
+	while (i <= nb / 2)
 	{
 		if (nb % i == 0)
 		{
 			return (0);
 		}
 		i++;
 	}
 	return (1);
 }
```

**The Mistake**
`1` is not a prime number, but your guard only rejects values `<= 0`.

**The Concept**
A prime number has exactly two positive divisors: `1` and itself. Since `1` has only one positive divisor, it is not prime.

### ex07 - `ft_find_next_prime.c`
No comparison: there is no matching reference file in the provided reference tree.

### ex08 - `ft_ten_queens_puzzle.c`
No comparison: there is no matching reference file in the provided reference tree.

## Summary

Most serious issues:

- Empty files: `C03/ex00`, `C03/ex03`
- Wrong function/prototype: `C03/ex01`, `C03/ex04`
- Runtime logic bugs: `C04/ex03`, `C05/ex00`, `C05/ex01`, `C05/ex02`, `C05/ex03`, `C05/ex06`
- Edge-case bug: `C04/ex02` fails on `-2147483648`
- Norm/style-only differences: `C03/ex02`, `C04/ex00`, `C04/ex01`, `C05/ex04`, `C05/ex05`

Files without reference counterparts in the provided tree:

- `C03/ex05/ft_strlcat.c`
- `C04/ex04/ft_putnbr_base.c`
- `C04/ex05/ft_atoi_base.c`
- `C05/ex07/ft_find_next_prime.c`
- `C05/ex08/ft_ten_queens_puzzle.c`
