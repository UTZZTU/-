#include <bits/stdc++.h>
using namespace std;
set<pair<string,string>> st;
int n;
string u,v;
int main ()
{
	cin>>n;
	getchar();
	while(n--)
	{
		cin>>u>>v;
		st.insert({u,v});
	}
	cout<<st.size();
	return 0;
}