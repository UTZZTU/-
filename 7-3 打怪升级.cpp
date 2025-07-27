#include <bits/stdc++.h>
using namespace std;
struct road
{
	int from,to,need,value;
	road(int x,int y,int z,int u):from(x),to(y),need(z),value(u){}
};
vector<road> e[1010];
int n,m,mx=9999999;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int a1,a2,a3,a4,mb,nl=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a1>>a2>>a3>>a4;
		e[a1].push_back({a1,a2,a3,a4});
		e[a2].push_back({a2,a1,a3,a4});
		
	}
	
	return 0;
}