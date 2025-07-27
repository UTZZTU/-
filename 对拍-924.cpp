#include <bits/stdc++.h>
using namespace std;
int f[10][10][10],res;
set<multiset<int>> st;
void dfs(int x,multiset<int> s)
{
//	cout<<s.size()<<endl;
	if(x==6)
	{
		if(s.size()==5)
		{
			for(auto it=s.begin();it!=s.end();it++)
			{
				cout<<*it<<" ";
			}
			cout<<endl;
			st.insert(s);
		}
		return;
	}
	for(int i=1;i<=4;i++)
	{
		multiset<int> v=s;
		v.insert(i);
		dfs(x+1,v);
	}
}
int main ()
{
	multiset<int> s;
	dfs(1,s);
	cout<<st.size();
	return 0;
}