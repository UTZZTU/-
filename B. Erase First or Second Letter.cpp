#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,res;
string s;
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s;
		res=0;
		set<int> st;
		for(int i=0;i<n;i++)
		{
			res+=st.size();
			st.insert(s[i]-'a');
		}
		res+=st.size();
		cout<<res<<endl;
	}
	return 0;
}