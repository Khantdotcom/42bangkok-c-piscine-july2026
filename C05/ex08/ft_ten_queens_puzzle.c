#include <unistd.h>

void print_board(int board[10])
{
    int     i;
    char    c;

    i = 0;
    while (i < 10)
    {
        c = board[i] + '0';
        write(1, &c, 1);
        i++;
    }
    write(1, "\n", 1);
}

int is_safe(int board[10], int row, int col)
{
    int i;

    i = 0;
    while (i < col)
    {
        if (board[i] == row || 
            board[i] - row == col - i || 
            row - board[i] == col - i)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

void solve(int board[10], int col, int *count)
{
    int row;

    if (col == 10)
    {
        print_board(board);
        (*count)++;
        return ;
    }
    
    row = 0;
    while (row < 10)
    {
        if (is_safe(board, row, col))
        {
            board[col] = row;
            solve(board, col + 1, count);
        }
        row++;
    }
}

int ft_ten_queens_puzzle(void)
{
    int board[10];
    int count;
    int i;

    i = 0;
    while (i < 10)
    {
        board[i] = 0;
        i++;
    }
    count = 0;
    solve(board, 0, &count);
    return (count);
}
