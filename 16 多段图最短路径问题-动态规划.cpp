#include <iostream>

const int MAX = 1000;
int arc[MAX][MAX] = { -1 };
int CreatGraph()
{
	int i, j, k;
	int vnum, arcnum;//vnum顶点个数，arcnum边个数
	int weight;

	std::cout << "请输入顶点个数和边的个数：" << std::endl;
	std::cin >> vnum >> arcnum;

	for (i = 0;i < vnum;i++)
	{
		for (j = 0;j < vnum;j++)
		{
			arc[i][j] = MAX;           //初始化代价矩阵
		}
	}

	for (k = 0;k < arcnum;k++)
	{
		std::cin >> i >> j >> weight;
		arc[i][j] = weight;
	}

	return vnum;
}

int BackGraph(int n)                            //求n个顶点的多段图的最短路径
{
	int i, j, temp;

	int cost[MAX], path[MAX];                  //存储路径长度和路径
	
	for (i = 1;i < n;i++)
	{
		cost[i] = MAX;
		path[i] = -1;
	}
	cost[0] = 0;                                //顶点为0是源点
	path[0] = -1;

	for (j = 1;j < n;j++)
	{
		for (i = j - 1;i >= 0;i--)              //考察所有入边
		{
			if (arc[i][j] + cost[i] < cost[j])
			{
				cost[j] = arc[i][j] + cost[i];
				path[j] = i;
			}
		}
	}

	std::cout << n - 1;                        //输出终点

	i = n - 1;

	while (path[i] >= 0)
	{
		std::cout << "<- " << path[i];
		i = path[i];
	}

	return cost[n-1];
}
