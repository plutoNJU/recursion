#include <iostream>
using namespace std;

int IncreaseOrder(int a[], int n)
{

	int i, j, k, index;
	int L[10];                                                //假设最多10个元素
	int x[10][10];

	for (i = 0;i < n;i++)
	{
		L[i] = 1;
		x[i][0] = a[i];
	}

	for (i = 1;i < n;i++)                                    //依次计算a[0]~a[i]的最长递增子序列
	{
		int max = 1;                                         //初始化递增子序列长度的最大值
		for (j = i - 1;j >= 0;j--)                           //对所有aj<ai
		{
			if ((a[j] < a[i]) && (max < L[j] + 1))
			{
				max = L[j] + 1;
				L[i] = max;
				
				for (k = 0;k < max - 1;k++)                 //存储最长递增子序列
				{
					x[i][k] = x[j][k];
				}

				x[i][max - 1] = a[i];
			}
		}
	}

	for (index = 0, i = 1;i < n;i++)                       //求所有递增子序列的最大长度
	{
		if (L[index] < L[i])
			index = i;
	}
	cout << "最长递增子序列是： ";
	for (i = 0;i < L[index];i++)                           //输出最长递增子序列
		cout << x[index][i] << " ";

	return L[index];                                       //返回最长递增子序列的长度
}
