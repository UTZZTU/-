#include <bits/stdc++.h>
using namespace std;
int n,m,k,maxx,l,r;
vector<int> vec;
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(!k)
		vec.push_back(i);
	}
	if(vec.size()<=m)
	cout<<n-vec.size();
	else
	{
		l=1,r=vec[m]-1;
		maxx=max(maxx,r-l+1-m);
		for(int i=m;i<vec.size();i++)
		{
			if(i==vec.size()-1)
			{
				r=n;
				l=vec[i-m]+1;
			}
			else
			{
				l=vec[i-m]+1;
				r=vec[i+1]-1;
			}
			maxx=max(maxx,r-l+1-m);
		}
		cout<<maxx;
	}
	return 0;
}