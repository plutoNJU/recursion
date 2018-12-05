#include <iostream>
using namespace std;

/*
	将两个有序序列r[s]~r[m]和r[m+1]~r[t]合并成一个有序序列r1[s]~r1[t]

*/
void merge(int r[], int r1[], int s, int m, int t)
{
	int i = s, j = m + 1, k = s;
	while (i<=m && j<=t)
	{
		if (r[i] <= r[j])
			r1[k++] = r[i++];
		else
			r1[k++] = r[j++];
	}

	while (i<=m)
	{
		r1[k++] = r[i++];
	}
	while (j<=t)
	{
		r1[k++] = r[j++];
	}
}
/*
对r[s]~r[t]进行归并排序
*/
void MergeSort(int r[], int s, int t)
{
	int m = 0;
	int r1[1000];
	
	if (s == t)
		return;
	else
	{
		m = (s + t) / 2;
		MergeSort(r, s, m);
		MergeSort(r, m + 1, t);
		merge(r, r1,s, m, t);

		for (int i = s; i <= t; i++)
		{
			r[i] = r1[i];
		}
		
	}
	
}

int main()
{
	int a[] = { 23,67,89,12,34,32,42,67,89 };
	printf("%d\n", a[0]);
	MergeSort(a, 0, 8);

	printf("a:------------------");
	for (int i = 0;i <= 8;i++)
	{
		
		cout << a[i] << " ";
	}

	system("pause");
	return 0;
}
