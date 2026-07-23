#include <stdlib.h>

static int	is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	word_count(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && is_sep(*s))
			s++;
		if (*s)
			count++;
		while (*s && !is_sep(*s))
			s++;
	}
	return (count);
}

static char	*dup_word(char *start, int len)
{
	char	*w;
	int		i;

	w = (char *)malloc((len + 1) * sizeof(char));
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

char	**ft_split(char *str)
{
	char	**arr;
	int		wc;
	int		i;
	int		len;

	wc = word_count(str);
	arr = (char **)malloc((wc + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str))
			str++;
		len = 0;
		while (str[len] && !is_sep(str[len]))
			len++;
		if (len > 0)
			arr[i++] = dup_word(str, len);
		str += len;
	}
	arr[i] = 0;
	return (arr);
}
