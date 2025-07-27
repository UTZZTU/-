#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int f[40010];
struct wp
{
	int value,weight;
};
vector<wp> p;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,e,v,w,m;
	cin>>n>>e;
	for(int i=1;i<=n;i++)
	{
		cin>>v>>w>>m;
		for(int j=1;j<=m;j*=2)
		{
			m-=j;
			p.push_back({j*v,j*w});
		}
		if(m)
		{
			p.push_back({m*v,m*w});
		}
	}
	for(auto it:p)
	{
		for(int j=e;j>=it.weight;j--)
		f[j]=max(f[j],f[j-it.weight]+it.value);
	}
	cout<<f[e];
	return 0;
}