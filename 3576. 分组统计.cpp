#include <bits/stdc++.h>
using namespace std;
int t,n,k,f[1010],maxx;
int main ()
{
	cin>>t;
	while(t--)
	{
		set<int> st;
		map<int,map<int,int>> mp;
		maxx=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>f[i];
			st.insert(f[i]);
		}
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			maxx=max(maxx,k);
			mp[k][f[i]]++;
		}
		for(int i=1;i<=maxx;i++)
		{
			cout<<i<<"={";
			for(auto it=st.begin();it!=st.end();it++)
			{
				if(it!=st.begin()) cout<<",";
				cout<<*it<<"="<<mp[i][*it];
			}
			cout<<"}"<<endl;
		}
	}
	return 0;
}