#include <iostream>
using namespace std;

int commFactor1(int m, int n)
{
	if (m <= 0 || n <= 0)
	{
		return 0;
	}
	if (m < n)
	{
		int temp = m;
		m = n;
		n = temp;
		return commFactor1(m, n);
	}

	if (m%n == 0)
		return n;
	else
	{
		for (int i = n;i >= 2;i--)
		{
			if ((m%i == 0) && (n%i == 0))
				return i;
		}
		return 1;
	}
}

int commFactor2(int m, int n)
{
	if (m <= 0 || n <= 0)
		return 0;
	if (m < n)
		return commFactor2(n, m);
	if (m%n == 0)
		return n;
	else
	{
		int r = m%n;
		while (r != 0)
		{
			m = n;
			n = r;
			r = m%n;
		}
		return n;
	}
}


int main02()
{
	int res1 = commFactor1(64, -128);
	printf("--%d---\n", res1);

	int res2 = commFactor2(64, -128);
	printf("--%d---\n", res2);

	printf("starting------");
	system("pause");
	return 0;
}
