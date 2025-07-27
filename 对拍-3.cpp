#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100010];
int get_num(int x)
{
	int pos=upper_bound(a+1,a+1+n,x)-a;
	pos--;
	for(int i=pos;i>=1;i--)
	{
		if(x>=a[i]) x-=a[i];
		if(x==0) break;
	}
	return x;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;;i++)
	{
		int num=get_num(i);
		if(num)
		{
			printf("%d",i);
			return 0;
		}
	}
	return 0;
}

/*
10
1 3 7 5 4 11 2 99 78 44
34
*/