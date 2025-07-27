#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,v;
};
bool cmp(node a,node b)
{
	if(a.x!=b.x)
	return a.x<b.x;
	else
	return a.y<b.y;
}
map<double, vector<node> > mp;
int main ()
{
	int n;
	cin>>n;
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		int x,y,v;
		cin>>x>>y>>v;
		sum+=v;
		mp[y*1.0/x].push_back(node{x,y,v});
	}
	for(auto it:mp)
	{
		vector<node> vc=it.second;
		sort(vc.begin(),vc.end(),cmp);
		for(int i=0;i<vc.size();i++)
		{
			if(i==0||vc[i].v!=1||vc[i-1].v!=1)
			cnt++;
		}
	}
	cout<<sum<<" "<<cnt;
	return 0;
}