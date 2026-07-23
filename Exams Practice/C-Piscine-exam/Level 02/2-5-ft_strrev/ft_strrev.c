char	*ft_strrev(char *str)
{
	int	l;
	int	r;
	char	tmp;

	l = 0;
	r = 0;
	while (str[r])
		r++;
	r--;
	while (l < r)
	{
		tmp = str[l];
		str[l] = str[r];
		str[r] = tmp;
		l++;
		r--;
	}
	return (str);
}