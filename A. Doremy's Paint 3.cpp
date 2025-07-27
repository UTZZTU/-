#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int main ()
{
	cin>>t;
	while(t--)
	{
		map<int,int> mp;
		set<int> st;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			st.insert(k);
			mp[k]++;
		}
		if(st.size()>=3)
		{
			puts("No");
		}
		else if(st.size()==1)
		{
			puts("Yes");
		}
		else
		{
			int l=*st.begin(),r=*st.rbegin();
			if(mp[l]==n/2&&mp[r]==n-n/2||mp[l]==n-n/2&&mp[r]==n/2) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}