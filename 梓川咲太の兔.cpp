#include<stdio.h>
int main()
{
	long long int a[55] = { 1,1,1,2 };
	int i,n;
		scanf("%d", &n);
		for (i = 4;i<n; i++)
		{
			a[i] = a[i - 1] + a[i - 3];
		}
		printf("%d", a[n-1]);
    return 0;
}

