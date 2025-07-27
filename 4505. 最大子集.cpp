#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[200010],n,maxx;
vector<ll> vec;
int main ()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld",&f[i]);
	sort(f+1,f+1+n);
	for(int i=1;i<=n;i++)
	{
		vector<ll> p;
		p.push_back(f[i]);
		for(int j=0;j<=30;j++)
		{
			int pos1=lower_bound(f+1,f+1+n,p[0]+pow(2,j))-f;
			if(pos1>n||f[pos1]!=p[0]+pow(2,j))
			continue;
			p.push_back(f[pos1]);
			int pos2=lower_bound(f+1,f+1+n,2*p[1]-p[0])-f;
			if(pos2<=n&&f[pos2]==2*p[1]-p[0])
			p.push_back(f[pos2]);
			if(p.size()>maxx)
		    {
			   maxx=p.size();
			   vec=p;
		    }
		    p.erase(p.begin()+1,p.end());
		    if(maxx==3)
		    break;
		}
		if(maxx==3)
		break;
	}
	if(maxx==0)
	{
		printf("1\n");
		printf("%lld",f[1]);
	}
	else
	{
		cout<<maxx<<endl;
	for(int i=0;i<vec.size();i++)
	cout<<vec[i]<<" ";
	}
	return 0;
}