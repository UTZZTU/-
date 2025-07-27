#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int main ()
{
	while(cin>>n>>m)
	{
		set<int> st;
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			st.insert(k);
		}
		for(int i=1;i<=m;i++)
		{
			cin>>k;
			st.insert(k);
		}
		for(auto it=st.begin();it!=st.end();it++)
		{
			if(it!=st.begin())
			cout<<" ";
			cout<<*it;
		}
		cout<<endl;
	}
	return 0;
}