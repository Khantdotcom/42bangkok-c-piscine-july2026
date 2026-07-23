int ft_sqrt(int nb)
{
    int i;

    // A negative number or 0 does not have a positive integer square root
    if (nb <= 0)
    {
        return (0);
    }

    i = 1;

	while (i <= nb/i)
	{
		if(i * i == nb)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
