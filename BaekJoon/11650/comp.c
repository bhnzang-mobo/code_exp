#include <stdio.h>

int num;
int x[100000];
int y[100000];

void quick(int start, int end,int arr[],int arr2[])
{
	int p = arr[(start + end)/2];
	int s = start;
	int e = end;
	
	while (s<=e)
	{
		while (arr[s] < p && s <= e)s++;
		while (p < arr[e] && s <= e)e--;

		if (s <= e)
		{
			int tmp = arr[s];
			arr[s] = arr[e];
			arr[e] = tmp;

			tmp = arr2[s];
			arr2[s] = arr2[e];
			arr2[e] = tmp;
			s++; e--;
		}
	}

	if (start < e)quick(start,e,arr,arr2);
	if (s < end)quick(s, end, arr, arr2);
}


// Á¤·Ä ¿ÖÇÏ»ï
// ÇÊ¿ä ¾ø»ï
int main()
{
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}

	quick(0, num - 1, x, y);

	int sameCnt=0;
	for (int i = 0; i < num; i++)
	{
		if (x[i] == x[i + 1])
		{
			sameCnt++;
		}
		else if (sameCnt!=0)
		{
			quick(i - sameCnt, i, y, x);
			sameCnt = 0;
		}
	}

	for (int i = 0; i < num; i++)
	{
		printf("%d %d\n", x[i], y[i]);
	}

	

	return 0;
}
