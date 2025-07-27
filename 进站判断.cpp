#include <bits/stdc++.h>
using namespace std;
string u,v;
int n;
int main ()
{
	cin>>n;
	getchar();
	while(n--)
	{
		stack<char> st;
		cin>>u>>v;
		int j=0;
		if(u.size()!=v.size())
		{
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=0;i<u.size();i++)
		{
			if(u[i]==v[j])
			{
				j++;
				while(!st.empty()&&st.top()==v[j]&&j<v.size())
				{
					st.pop();
					j++;
				}
			}
			else
			st.push(u[i]);
		}
		if(st.empty())
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}