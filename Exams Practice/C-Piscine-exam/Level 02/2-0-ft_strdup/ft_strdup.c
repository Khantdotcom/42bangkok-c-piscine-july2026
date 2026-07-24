#include <stdlib.h>

/*
** ft_strdup - allocates a fresh copy of src on the heap.
**
** Why we need it:
**   Strings passed as argv or literals may live in read-only memory.
**   strdup gives you an owned, mutable, heap-allocated copy.
**
** Steps:
**   1. Measure length manually (no strlen allowed).
**   2. malloc(len + 1): +1 for the null terminator. Using sizeof(char)
**      is always 1 but makes intent explicit.
**   3. NULL-check malloc: heap can fail; returning NULL signals failure
**      to the caller without crashing.
**   4. Copy bytes one-by-one, then append '\0' explicitly.
**
** Ownership rule: caller must free() the returned pointer when done.
*/
char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dst;

	/* Count characters, stopping at null terminator */
	len = 0;
	while (src[len])
		len++;
	/* Allocate: len bytes for content + 1 byte for '\0' */
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)   /* malloc returns NULL if heap exhausted */
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0'; /* null-terminate the copy */
	return (dst);
}
