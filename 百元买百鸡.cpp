/*
公鸡5元一只，母鸡3元一只，小鸡1元三只
用一百元买一百只鸡
问公鸡，母鸡，小鸡各几何
*/
#include <iostream>
using namespace std;

void Chicken()
{
	int x = 0;
	int y = 0;
	int z = 0;
	int count = 0;
	for(x=0;x<=20;x++)
		for (y = 0;y < 33;y++)
		{
			z = 100 - x - y;
			if ((z % 3 == 0) && (5 * x + 3 * y + z / 3) == 100)
			{
				cout << "公鸡：" << x << " 母鸡：" << y << " 小鸡：" << z << endl;
				count++;
			}
		}
	if (count == 0)
		cout << "无解--" << endl;
}
int main()
{
	Chicken();
	system("pause");
	return 0;
}
