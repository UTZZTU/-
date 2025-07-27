#include <bits/stdc++.h>
using namespace std;
set<char> st;
string u;
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		st.insert(u[i]);
	}
	if(st.size()&1)
	{
		cout<<"odd";
	}
	else
	cout<<"even";
	return 0;
}