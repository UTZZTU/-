#include <bits/stdc++.h>
using namespace std;
map<string,bool> mp;
string u,v;
int n,js;
int main ()
{
	cin>>n;
	getchar();
	while(n--)
	{
		cin>>u;
		cin>>v;
		if(!mp.count(u+v))
		{
			int t=4;
			while(t--)
			{
				mp[u+v]=true;
				char c=u[0];
				u[0]=v[0];
				v[0]=v[1];
				v[1]=u[1];
				u[1]=c;
			}
			js++;
		}
		if(n)
		cin>>u;
	}
	cout<<js;
	return 0;
}