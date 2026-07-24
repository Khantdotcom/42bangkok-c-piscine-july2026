/*
** ft_strlen - counts characters in str up to (not including) '\0'.
**
** How it works:
**   Use len as an index. str[len] is truthy for any non-zero byte
**   and falsy (0) when it hits the null terminator.
**   Incrementing stops exactly at '\0', so len holds the count.
**
** Edge case:
**   - Empty string "" -> str[0] == '\0' -> loop never runs -> returns 0. Correct.
**
** No pointer arithmetic used here; index-based loop avoids
** modifying the original pointer (useful if caller still needs it).
*/
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len]) /* falsy when str[len] == '\0' */
		len++;
	return (len);
}
