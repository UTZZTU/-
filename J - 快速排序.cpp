#include <bits/stdc++.h>
using namespace std;
#define il inline
int n,f[100010];
il int read()
{
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*k;
}
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
int main ()
{
	n=read();
	for(int i=1;i<=n;i++)
	f[i]=read();
	quick_sort(f,1,n);
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		printf(" ");
		printf("%d",f[i]);
	}
	return 0;
}