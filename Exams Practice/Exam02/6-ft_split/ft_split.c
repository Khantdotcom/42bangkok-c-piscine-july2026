#include <stdlib.h>

/*
** is_sep - returns 1 if c is a word separator (space, tab, or newline).
**   Centralising the separator test avoids repeating the same condition
**   in three different loops.
*/
static int	is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/*
** word_count - counts the number of words in s.
**
** A word is any non-separator sequence. The three-loop pattern:
**   1. Skip separators (skip the gap between words).
**   2. If we hit a non-separator, a word starts -> count++.
**   3. Skip non-separators (skip the word itself).
** Repeat until end of string.
**
** This is needed to size the pointer array in ft_split.
*/
static int	word_count(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && is_sep(*s))   /* skip leading/inter-word separators */
			s++;
		if (*s)                    /* non-separator found: a word starts */
			count++;
		while (*s && !is_sep(*s))  /* skip the word */
			s++;
	}
	return (count);
}

/*
** dup_word - allocates and copies exactly 'len' characters from start.
**   Like a bounded strdup. Returns NULL on allocation failure.
*/
static char	*dup_word(char *start, int len)
{
	char	*w;
	int		i;

	w = (char *)malloc((len + 1) * sizeof(char)); /* +1 for '\0' */
	if (!w)
		return (0);
	i = 0;
	while (i < len)
	{
		w[i] = start[i];
		i++;
	}
	w[len] = '\0';
	return (w);
}

/*
** ft_split - splits str into words and returns a NULL-terminated char** array.
**
** Memory layout of the result:
**   arr[0]   -> "first"
**   arr[1]   -> "second"
**   ...
**   arr[wc]  -> NULL   (sentinel; callers use this to know where the array ends)
**
** Why count words first?
**   malloc needs an exact size. word_count gives us wc, so we allocate
**   (wc + 1) pointers: one per word plus one NULL sentinel.
**
** Main fill loop:
**   1. Skip separators to reach the start of the next word.
**   2. Measure the word length (scan forward without moving str yet).
**   3. dup_word allocates and fills the word string.
**   4. Advance str by len to move past the word.
**   Repeat until str == '\0'.
**
** Ownership: caller must free each string in arr, then free arr itself.
**
** Edge cases:
**   - Empty string ""     -> word_count=0, arr has one NULL slot. Correct.
**   - Only separators     -> word_count=0, same. Correct.
**   - Trailing separators -> len ends up 0 after last word; str+=0 loop
**                           exits naturally when *str=='\0'. Correct.
*/
char	**ft_split(char *str)
{
	char	**arr;
	int		wc;  /* word count */
	int		i;
	int		len; /* length of current word */

	wc = word_count(str);
	arr = (char **)malloc((wc + 1) * sizeof(char *)); /* +1 for NULL sentinel */
	if (!arr)
		return (0);
	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str))   /* skip separators */
			str++;
		len = 0;
		while (str[len] && !is_sep(str[len])) /* measure word */
			len++;
		if (len > 0)
			arr[i++] = dup_word(str, len); /* allocate and store the word */
		str += len;                        /* advance past the word */
	}
	arr[i] = 0; /* NULL-terminate the pointer array */
	return (arr);
}
