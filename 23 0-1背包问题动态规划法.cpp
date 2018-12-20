//0/1背包问题动态规划法
//时间复杂度O(n*C)
#include<iostream>
using namespace std;
int const MAX77 = 100;
int V[MAX77][MAX77] = { 0 };


int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int KnapSack(int w[], int v[],int n, int C)//w物品重量数组 v物品价值数组 C背包容量 n个物品
{
	int x[n] = { 0 };
	int i, j;
	for (i = 0;i <= n;i++)
		V[i][0] = 0;
	for (j = 0;j <= n;j++)
		V[0][j] = 0;

	for (i = 1;i <= n;i++)
		for (j = 1;j <= C;j++)
			if (j < w[i])
				V[i][j] = V[i - 1][j];
			else
				V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);

	for (j = C, i = n;i > 0;i--)
	{
		if (V[i][j] > V[i - 1][j])
		{
			x[i] = 1;
			j = j - w[i];
		}
		else
			x[i] = 0;
	}


	return V[n][C];//返回背包取得最大价值
}
