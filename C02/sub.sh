#!/bin/bash

# Create all directories from ex00 to ex12
mkdir -p ex00 ex01 ex02 ex03 ex04 ex05 ex06 ex07 ex08 ex09 ex10 ex11 ex12

# Create the corresponding .c files inside each directory
touch ex00/ft_strcpy.c
touch ex01/ft_strncpy.c
touch ex02/ft_str_is_alpha.c
touch ex03/ft_str_is_numeric.c
touch ex04/ft_str_is_lowercase.c
touch ex05/ft_str_is_uppercase.c
touch ex06/ft_str_is_printable.c
touch ex07/ft_strupcase.c
touch ex08/ft_strlowcase.c
touch ex09/ft_strcapitalize.c
touch ex10/ft_strlcpy.c
touch ex11/ft_putstr_non_printable.c
touch ex12/ft_print_memory.c

echo "Directories and files for ex00 to ex12 have been created successfully."