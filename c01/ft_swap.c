#include <unistd.h>

void    ft_swap(char *a,char *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void){
    char a = 'g';
    char b= 'b';
    ft_swap(&a,&b);
    write(1,&a,1);
    write(1,&b,1);
}