#include <iostream>
using namespace std;
//最大子序列和问题分治求解

int maxSum(int a[], int left, int right)
{
	int sum = 0;
	int midSum = 0;
	int leftSum = 0;
	int rightSum = 0;

	int center = 0, s1 = 0, s2 = 0, lefts = 0, rights = 0;
	
	//如果序列长度为1，返回值
	if (left == right)
		sum = a[left];
	else
	{
		center = (left + right) / 2;
		//递归求解
		leftSum = maxSum(a, left, center);
		rightSum = maxSum(a, center + 1, right);
		
		//中间求解
		s1 = 0;
		lefts = 0;

		for (int i = center;i >= left;i--)
		{
			lefts = lefts + a[i];
			if (lefts > s1)
				s1 = lefts;
		}

		s2 = 0;
		rights = 0;

		for (int j = center + 1;j <= right;j++)
		{
			rights = rights + a[j];
			if (rights > s2)
				s2 = rights;
		}

		midSum = s1 + s2;

		//比较三个值的大小
		if (midSum < leftSum)
			sum = leftSum;
		else
			sum = midSum;
		if (sum < rightSum)
			sum = rightSum;
	}
	return sum;
}

int main()
{
	int a[] = {-20,11,-4,13,-5,-2 };
	for (int i = 0;i <= 5;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	int sum = 0;
	sum = maxSum(a, 0, 5);
	cout << " " << sum << endl;

	system("pause");
	return 0;

}
