#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ae,be,ce,ar,br,cr,x,y,res[4];
int main ()
{
	scanf("%lld",&n);
	scanf("%lld%lld%lld",&ae,&be,&ce);
	scanf("%lld%lld%lld",&ar,&br,&cr);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x,&y);
		ll t1=ae*x+be*y+ce,t2=ar*x+br*y+cr;
		if(t1<0&&t2<0)
		res[0]++;
		else if(t1<0&&t2>0)
		res[1]++;
		else if(t1>0&&t2<0)
		res[2]++;
		else
		res[3]++;
	}
	sort(res,res+4);
	for(int i=0;i<4;i++)
	cout<<res[i]<<" ";
	return 0;
}