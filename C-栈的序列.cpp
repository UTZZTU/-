#include <bits/stdc++.h>
using namespace std;
int n;
string u,v;
int main ()
{
	cin>>n;
	getchar();
	while(n--)
	{
		cin>>u>>v;
		stack<char> st;
		int i=0,j=0;
		for(i;i<u.size();i++)
		{
			if(u[i]==v[j])
			{
				j++;
				while(!st.empty()&&st.top()==v[j])
				{
					st.pop();
					j++;
				}
			}
			else
			st.push(u[i]);
		}
		if(st.empty()&&i==u.size()&&j==u.size())
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}