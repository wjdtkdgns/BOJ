#include <iostream>

using namespace std;

int tl[1000001] = { 0,1,2 };

int main()
{
	int x;
	cin >> x;
	for (int i = 3; i <= x; i++)
	{
		tl[i] = tl[i - 2] + tl[i - 1];
		if (tl[i] >= 15746)
			tl[i] %= 15746;
	}
	cout << tl[x] << endl;
	return 0;
}