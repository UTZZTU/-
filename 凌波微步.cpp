#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		set<int> st;
		while(n--)
		{
			cin>>k;
			st.insert(k);
		}
		cout<<st.size()<<endl;
	}
	return 0;
}