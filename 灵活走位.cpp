#include <bits/stdc++.h>
using namespace std;
int n,res,l[20];
map<pair<int,int>,int> mp1,mp2;
vector<int> vec;
void dfs(int level)
{
	if(level==n+1)
	{
		res++;
//		for(int i=0;i<vec.size();i++) cout<<vec[i]<<" ";
//		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		int x=level,y=i;
		int minn=min(x-1,y-1);
		x-=minn,y-=minn;
		minn=min(n-i,level-1);
		if(!l[i]&&mp1[{x,y}]==0&&mp2[{level-minn,i+minn}]==0)
		{
			l[i]=1;
			mp1[{x,y}]=1;
			mp2[{level-minn,i+minn}]=1;
			vec.push_back(i);
			dfs(level+1);
			vec.pop_back();
			mp2[{level-minn,i+minn}]=0;
			l[i]=0;
			mp1[{x,y}]=0;
		}
	}
}
int main ()
{
	cin>>n;
	dfs(1);
	cout<<res;
	return 0;
}