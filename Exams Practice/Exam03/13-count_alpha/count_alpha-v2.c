#include <stdio.h>
#include <unistd.h>

int is_alpha(char c)
{
    if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
        return (1);
    return (0);
}

char ft_tolower(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
        return (c + 32);
    return (c);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int counts[128] = {0}; // Array to hold counts (initialized to 0)
        int i = 0;
        char c;
        int first = 1; // Flag to handle the comma separation

        // Pass 1: Count the occurrences of each letter
        while (argv[1][i])
        {
            c = argv[1][i];
            if (is_alpha(c) == 1)
            {
                counts[(int)ft_tolower(c)] += 1;
            }
            i++;
        }

        // Pass 2: Print in the order of appearance
        i = 0;
        while (argv[1][i])
        {
            c = argv[1][i];
            if (is_alpha(c) == 1)
            {
                c = ft_tolower(c);
                if (counts[(int)c] > 0)
                {
                    // Print a comma before every element EXCEPT the first one
                    if (first == 0)
                    {
                        printf(", ");
                    }
                    
                    // Print the count and the character
                    printf("%d%c", counts[(int)c], c);
                    
                    first = 0; // We have now printed at least one element
                    counts[(int)c] = 0; // Set to 0 so we don't print it again
                }
            }
            i++;
        }
    }
    printf("\n"); // Always print a newline at the end
    return (0);
}