#include <unistd.h>
void    ft_ft(char *nbr){
    *nbr = 42;
}

int main(void){
    int j = 0;
    ft_ft(&j);
}