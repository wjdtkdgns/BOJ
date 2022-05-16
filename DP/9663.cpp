#include<iostream>

using namespace std;

int n;

bool is_valid(int board[], int depth){
    int	y;
	int	cmp_x;
    int x;

	y = 0;
	while (y < depth)
	{
		cmp_x = board[y];
		x = board[depth];
		if (y == depth || cmp_x == x)
			return (0);
		if (abs(y - depth) == abs(cmp_x - x))
			return (0);
		y++;
	}
	return (1);
}

int	set_queen(int board[], int depth)
{
	int	rtn;
	int	x;

    if(depth==n)
        return 1;
	rtn = 0;
	x = 0;
	while (x < n)
	{	
        board[depth]=x;
		if (is_valid(board, depth)){
			rtn += set_queen (board, depth + 1);
        }
        board[depth]=0;
		x++;
	}
	return (rtn);
}

void	init(int board[])
{
	int		x;

	x = 0;
	while (x < 15)
	{
		board[x] = -1;
		x++;
	}	
}

int	main(void)
{
	int		board[15];
	int		x_idx;
	int		ans;

	init(board);
    cin>>n;
	x_idx = 0;
	ans = 0;
    cout<<set_queen(board, 0);
}