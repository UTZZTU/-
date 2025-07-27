#include <bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010];
bool check(int x)
{
	int res=0;
	for(int i=n;i>=1;i--)
	{
		if(i==x) continue;
		if(res==0) res=b[i];
		else res=(res+b[i])/2;
	}
	return res<=b[x];
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=b[l]) printf("1");
		else printf("0");
	}
	return 0;
}