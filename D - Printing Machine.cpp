#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int n,cnt,res;
struct node
{
	int t,d,pos;
}s[200010];
bool cmp(node x,node y)
{
	if(x.pos!=y.pos) return x.pos<y.pos;
	else return x.t<y.t;
}
signed main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&s[i].t,&s[i].d);
		s[i].pos=s[i].t+s[i].d;
	}
	sort(s+1,s+1+n,cmp);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<s[i].t<<" "<<s[i].d<<" "<<s[i].pos<<endl;
//	}
	for(int i=1;i<=n;i++)
	{
		if(s[i].t>cnt)
		{
			cnt=s[i].t;
			res++;
		}
		else if(s[i].t==cnt)
		{
//			if(cnt+1)
			if(cnt+1<=s[i].pos)
			{
				cnt+=1;
				res++;
			}
		}
		else if(cnt+1<=s[i].pos)
		{
			cnt+=1;
			res++;
		}
	}
	cout<<res;
	return 0;
}