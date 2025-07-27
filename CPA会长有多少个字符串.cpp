#include <bits/stdc++.h>
using namespace std;
set<string> st;
int n;
string u;
int main ()
{
	cin>>n;
	getchar();
	while(n--)
	{
		cin>>u;
		st.insert(u);
	}
	cout<<st.size();
	return 0;
}