#include <bits/stdc++.h>
using namespace std;
int f[10],flag1,flag2;
int trangle(int x,int y,int z)
{
	if(x==y+z||y==x+z||z==x+y) return 0;
	else if(x+y>z&&x+z>y&&y+z>x) return 1;
	else return -1;
}
void dfs(int level,vector<int> vec)
{
	if(level>=5)
	{
		if(vec.size()==3)
		{
			int s=trangle(vec[0],vec[1],vec[2]);
			if(s>0) flag1++;
			else if(s==0) flag2++;
		}
		return;
	}
	vec.push_back(f[level]);
	dfs(level+1,vec);
	vec.pop_back();
	dfs(level+1,vec);
}
void solve()
{
	for(int i=1;i<=4;i++) cin>>f[i];
	vector<int> vec;
	dfs(1,vec);
	if(flag1)
	{
		cout<<"TRIANGLE"<<endl;
	}
	else if(flag2)
	{
		cout<<"SEGMENT"<<endl;
	}
	else
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}