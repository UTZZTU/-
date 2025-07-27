#include <bits/stdc++.h>
using namespace std;
int n,f[100010],t;
void quick_sort(int f[], int l, int r)
{
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = f[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (f[i] < x);
        do j -- ; while (f[j] > x);
        if (i < j) swap(f[i], f[j]);
    }
    quick_sort(f,l,j), quick_sort(f,j+1, r);
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
	    scanf("%d",&f[i]);
	    quick_sort(f,1,n);
	    for(int i=1;i<=n;i++)
	    {
		    if(i!=1)
		    printf(" ");
		    printf("%d",f[i]);
	    }
	    printf("\n");
	}
	return 0;
}