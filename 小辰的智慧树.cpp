#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int h,c;
}s[1000010];
bool cmp(node x,node y)
{
	return x.h<y.h;
}
int n,m,maxx,sum,cnt;
bool check(int x)
{
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i].h>x)
		{
			res+=min(s[i].h-x,s[i].h-s[i].c);
		}
		if(res>m) return false;
	}
	return true;
}
signed main ()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&s[i].h,&s[i].c);
		maxx=max(maxx,s[i].h);
	}
	sort(s+1,s+1+n,cmp);
	int l=0,r=1e6+10;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
//	cout<<l<<endl;
	for(int i=n;i>=1;i--)
	{
		if(s[i].h>l)
		{
			int t=max(l,s[i].c);
//			if(t>l)
//			{
				sum+=(s[i].h-t)*(s[i].h+t);
				cnt+=s[i].h-t;
//			}
//			else
//			{
////				t++;
//				sum+=(s[i].h-t)*(s[i].h+s[i].h-((s[i].h-t)));
//				cnt+=s[i].h-t;
//			}
		}
	}
//	cout<<sum<<" "<<l<<" "<<cnt<<endl;
	if(l!=0&&m-cnt>0)
	sum+=(m-cnt)*(l+l-1LL);
	printf("%lld",sum);
	return 0;
}
/*
3 9
10 5
9 2
8 1
*/