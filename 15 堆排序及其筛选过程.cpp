
//堆排序及其筛选过程

void SiftHeap(int r[], int k, int n)
{
	int i, j, temp;
	i = k;
	j = 2 * i + 1;
	while (j < n)
	{
		if (j < n - 1 && r[j] < r[j + 1])
			j++;
		if (r[i] > r[j])
			break;
		else
		{
			temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			i = j;
			j = 2 * i + 1;
		}
	}
}

void HeapSort(int r[], int n)
{

	int i, temp;
	for (i = (n - 1) / 2;i >= 0;i--)
	{
		SiftHeap(r, i, n);
	}
	for (i = 1;i < n - 1;i++)
	{
		temp = r[0];
		r[0] = r[n - i];
		r[n - i] = temp;
		SiftHeap(r, 0, n - i);
	}


}
