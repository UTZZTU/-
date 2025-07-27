# include <iostream>
using namespace std;
const int N = 1000010;
int a[N], q[N], hh, tt = -1,n,k;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	for(int i=0;i<=k&&i<n;i++)
	{
		while (hh <= tt && a[i] <= a[q[tt]]) -- tt;
		q[++ tt] = i; 
	}
	printf("%d",a[q[hh]]);
	for(int i=1;i<n;i++)
	{
		if((i-k)>q[hh]) ++hh;
		while (i+k<n&&hh <= tt && a[i+k] <= a[q[tt]]) -- tt;    // 若队尾不单调，tt减1
		if(i+k<n)
        q[++ tt] = i+k;
        printf(" %d",a[q[hh]]);
	}
    return 0;
}