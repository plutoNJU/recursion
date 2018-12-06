#include <iostream>
using namespace std;
//最近对分治求解
//初始点按照x的从小到大排列点集S

struct point
{
	int x,y;
};
double Distance(point a, point b);
void QuicksortByY(point P[], int first, int end);
void quickSort(point r[], int first, int end);

double ClosestPoint(point S[], int low, int high)
{
	double d1, d2, d3, d;
	int mid, i, j, index;
	point P[1000];                     //预设小于1000个点

	if ((high - low) == 1)
		//return Distance(S[low],S[high]);
		return Distance(S[low], S[high]);
	if ((high - low) == 2)
	{
		d1 = Distance(S[low], S[low + 1]);
		d2 = Distance(S[low + 1], S[high]);
		d3 = Distance(S[low], S[high]);
		if ((d1 < d2) && (d1 < d3))
			return d1;
		else if (d2 < d3)
			return d2;
		else
			return d3;
	}

	mid = (low + high) / 2;
	d1 = ClosestPoint(S, low, mid);
	d2 = ClosestPoint(S, mid + 1, high);
	
	if (d1 < d2)
		d = d1;
	else
		d = d2;

	//情况c的计算
	index = 0;
	for (i = mid;(i >= low) && ((S[mid].x - S[i].x) < d);i--)//建立点集P1
	{
		P[index++] = S[i];
	}
	for (i = mid + 1;(i <= high) && ((S[i].x - S[mid].x) < d);i++)//建立点集P2
	{
		P[index++] = S[i];
	}

	QuicksortByY(P, 0, index - 1);//对于集合P1和P2关于y坐标排序

	for (i = 0;i < index;i++)
	{
		for (j = i+1;j < index;j++)
		{
			if ((P[j].y - P[i].y) >= d)
				break;
			else
			{
				d3 = Distance(P[i], P[j]);
				if (d3 < d)
					d = d3;
			}
		}
	}
	return d;
}

double Distance(point a, point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void QuicksortByY(point P[], int first, int end)
{
	quickSort(P, first, end);
}

int Partition(point r[], int first, int end)
{
	int i = first, j = end;

	//右侧扫描
	while (i < j)
	{
		while (i < j && r[i].y <= r[j].y)
			j--;
		if (i < j)
		{
			//point temp = r[i];
			point temp;
			temp.x = r[i].x;
			temp.y = r[i].y;
			//r[i] = r[j];
			r[i].x = r[j].x;
			r[i].y = r[j].y;
			//r[j] = temp;
			r[j].x = temp.x;
			r[j].y = temp.y;
			i++;
		}
	}

	//左侧扫描
	while (i < j && r[i].y <= r[j].y)
		i++;
	if (i < j)
	{
		//int temp = r[i];
		point temp;
		temp.x = r[i].x;
		temp.y = r[i].y;
		//r[i] = r[j];
		r[i].x = r[j].x;
		r[i].y = r[j].y;
		//r[j] = temp;
		r[j].x = temp.x;
		r[j].y = temp.y;
		j--;
	}

	return i;
}

void quickSort(point r[], int first, int end)
{
	int pivot;
	if (first < end)
	{
		pivot = Partition(r, first, end);
		quickSort(r, first, pivot - 1);
		quickSort(r, pivot + 1, end);
	}
}
int main()
{
	point a,b,c,d,e,f,g,h;
	a.x = 1;a.y = 21;
	b.x = 3;b.y = 91;
	c.x = 4;c.y = 100;
	d.x = 5;d.y = 8;
	e.x = 6;e.y = 12;
	f.x = 8;f.y = 10;
	g.x = 10;g.y = 14;
	h.x = 19;h.y = 7;
	point P[] = {a,b,c,d,e,f,g,h};
	cout << P[0].x << " " << P[6].y << endl;

	//quickSort(P,0,7);
	for (int j = 0;j <= 7;j++)
	{
		cout << P[j].y;
		cout << " ";
	}
	cout << endl;
	cout << P[0].y << " " << P[6].y << endl;


	double sum = ClosestPoint(P, 0, 7);
	cout << "最近距离是：" << sum << endl;

	system("pause");
	return 0;

}
