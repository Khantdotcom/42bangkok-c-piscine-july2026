#include <unistd.h>

void	ft_swap(int *a, int *b)
{
    int temp;

    temp = &a;
    b = &temp;
    a = &b;
    //what is the different useages of pointers, references based on data types
}

int     main(void)
{
    int     a;
    int     b;

    a = 0;
    b = 1;
    ft_swap(&a, &b);

    char c;

    c = a + '0';

    char e;

    e = b  + '0';

    write(1,&c,1);
    write(1,&e,1);
}