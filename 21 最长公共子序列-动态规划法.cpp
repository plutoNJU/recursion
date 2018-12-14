#include <iostream>
using namespace std;

//********************************************************输出可能有问题

// x: a b c b d b
// y: a c b b a b d b b
// 这两个最长公共子序列是 acbdb
int const MAX = 100;
int L[MAX][MAX] = { -1 };//长度矩阵
int S[MAX][MAX] = { -1 };//状态矩阵

int CommonOrder(char x[],int m,char y[],int n,char z[]) // x和y分别是两个序列 m是序列x的长度，n是序列y的长度，z存储最长公共子序列
{
	
	int i, j, k;

	for (j = 0;j <= n;j++)    //初始化0行和0列
	{
		L[0][j] = 0;
	}
	for (i = 0;i <= m;i++)
	{
		L[i][0] = 0;
	}

	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
			if (x[i] = y[j])
			{
				L[i][j] = L[i - 1][j - 1] + 1;
				S[i][j] = 1;
			}
			else if (L[i][j - 1] >= L[i - 1][j])
			{
				L[i][j] = L[i][j - 1];
				S[i][j] = 2;
			}
			else
			{
				L[i][j] = L[i - 1][j];
				S[i][j] = 3;
			}

	i = m;
	j = n;
	k = L[m][n];

	while (i > 0 && j > 0)
	{
		if (S[i][j] == 1)
		{
			z[k] = x[i];
			k--;
			i--;
			j--;
		}
		else if (S[i][j] == 2)
		{
			j--;
		}
		else
			i--;
	}

	for (k = 0;k < L[m][n];k++)
	{
		cout << z[k];                      // 输出最长子序列
		//printf("%c", z[k]);
	}

	return L[m][n];                        //返回公公长度
}

int main()
{
	char x[] = { 'a', 'b', 'c', 'b', 'd', 'b' };
	char y[] = { 'a', 'c', 'b', 'b', 'a', 'b', 'd', 'b', 'b' };
	char z[MAX];

	int len = CommonOrder(x, 6, y, 9, z);
	cout << endl;
	cout << len << endl;
	system("pause");
	return 0;
}
