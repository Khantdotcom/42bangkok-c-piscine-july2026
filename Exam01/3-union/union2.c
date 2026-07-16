#include <unistd.h>

void ft_union(char *s1, char *s2)
{
    int seen[256] = {0};
    int i = 0;

    // Process the first string
    while (s1[i])
    {
        if (seen[(unsigned char)s1[i]] == 0)
        {
            write(1, &s1[i], 1);
            seen[(unsigned char)s1[i]] = 1;
        }
        i++;
    }

    i = 0;
    // Process the second string
    while (s2[i])å
    {
        if (seen[(unsigned char)s2[i]] == 0)
        {
            write(1, &s2[i], 1);
            seen[(unsigned char)s2[i]] = 1;åç
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    // argc == 3 means 1 program name + 2 arguments
    if (argc == 3)
    {
        ft_union(argv[1], argv[2]);
    }
    // Always print a newline at the end, whether arguments were valid or not
    write(1, "\n", 1);
    return (0);
}