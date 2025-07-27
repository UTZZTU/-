#include<stdio.h>
int main()
{
	int a[55] = { 1,2,3,4 };
	int i,t,j;
	for (j = 0;; j++)
	{
		scanf("%d", &t);
		if (t == 0)
			break;
		for (i = 4; i < 54; i++)
		{
			a[i] = a[i - 1] + a[i - 3];
		}
		printf("%d\n", a[t-1]);
	}
    return 0;
}

