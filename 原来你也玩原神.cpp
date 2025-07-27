#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
	int pos,x,a;
};
bool cmp(node x,node y)
{
	if(x.a!=y.a) return x.a>y.a;
	else return x.pos<y.pos;
}
map<int,vector<node> >mp;
int main ()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		node u;
		u.pos=i;
		cin>>u.x>>u.a;
		mp[u.x].push_back(u);	
	}
	for(int i=1;i<=m;i++)
	{
		vector<node> vec=mp[i];
		if(vec.size()==0) puts("-1");
		else
		{
			sort(vec.begin(),vec.end(),cmp);
			for(int j=0;j<vec.size();j++)
			{
				cout<<vec[j].pos<<" ";
			}
			cout<<endl;
		}
	}
    return 0;
}