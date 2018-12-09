#include<iostream>
using namespace std;
//减治法求解两个等长升序序列的中位数

int SearchjMid(int A[], int B[], int n)
{
	int s1 = 0, e1 = n - 1, s2 = 0, e2 = n - 1;
	int mid1, mid2;

	while (s1 < e1 && s2 < e2)
	{
		mid1 = (s1 + e1) / 2;//序列A的中位数数组下标
		mid2 = (s2 + e2) / 2;//序列B的中位数数组下标
		

		if (A[mid1] == B[mid2])//情况1
			return A[mid1];

		if (A[mid1] < B[mid2])//情况2
		{
			if ((s1 + e1) % 2 == 0)
				s1 = mid1;
			else
				s1 = mid + 1;
			e2 = mid2;
		}
		else				 //情况3
		{
			if ((s2 + e2) % 2 == 0)
				s2 = mid2;
			else
				s2 = mid2 + 1;
			e1 = mid1;
		}

	}
	if (A[s1] < B[s2])
		return A[s1];
	else
		return B[s2];
}
