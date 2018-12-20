
//八皇后问题 回溯法

#include<iostream>
using namespace std;

int const MAX777 = 100;
int x[MAX777] = { -1 };

int Place(int k)
{
	for (int i = 0;i < k;i++)
		if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k]))
			return 1;
}


void Queen(int n)
{
	int k = 0;

	while (k >= 0)
	{
		x[k]++;

		while (x[k] < n && Place(k) == 1)
		{
			x[k]++;
		}

		if (x[k] < n && k == n - 1)
		{
			for (int i = 0;i < n;i++)
				cout << x[i] + 1 << " ";
			cout << endl;
			return;
		}

		if (x[k] < n && k < n - 1)
			k = k + 1;
		else
			x[k--] = -1;
	}
	cout << "无解" << endl;
}
