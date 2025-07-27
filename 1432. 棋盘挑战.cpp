#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
int n,f1[101][101],f2[101][101],l[101],js;
vector<int> vec;
set<vector<int>>st;
void dfs(int level)
{
	if(level>n)
	{
		st.insert(vec);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		int num1=min(level-1,i-1),num2=min(level-1,n-i);
		if(f1[level-num1][i-num1]||f2[level-num2][i+num2]||l[i])
	    continue;
	    vec.push_back(i);
	    f1[level-num1][i-num1]=1,f2[level-num2][i+num2]=1,l[i]=1;
	    dfs(level+1);
	    vec.pop_back();
	    f1[level-num1][i-num1]=0,f2[level-num2][i+num2]=0,l[i]=0;
	}
	return;
}
int main ()
{
	cin>>n;
	dfs(1);
	for(auto it=st.begin();it!=st.end()&&js<=2;it++,js++)
	{
		vec=*it;
		for(int i=0;i<vec.size();i++)
		{
			if(i!=0)
			cout<<" ";
			cout<<vec[i];
		}
		cout<<endl;
	}
	cout<<st.size();
	return 0;
}