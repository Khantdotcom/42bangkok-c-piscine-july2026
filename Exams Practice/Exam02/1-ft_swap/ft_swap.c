/*
** ft_swap - swaps the integer values pointed to by a and b.
**
** Why pointers?
**   C passes arguments by value. If we took (int a, int b) we'd only
**   swap local copies; the caller's variables would be unchanged.
**   By accepting pointers (int *a, int *b), we dereference them to
**   reach and modify the original variables in the caller's scope.
**
** Classic three-variable swap:
**   tmp = *a   -> save a's value so it isn't lost when we overwrite it.
**   *a  = *b   -> copy b's value into a.
**   *b  = tmp  -> copy the saved a value into b.
**
** XOR swap (*a ^= *b; *b ^= *a; *a ^= *b) is an alternative but
** harder to read and fails when a == b (same address). tmp-swap is safer.
*/
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;  /* save a's original value */
	*a = *b;   /* overwrite a with b */
	*b = tmp;  /* overwrite b with saved a */
}
