#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
string s,t,p;
int maxx;
void solve()
{
	cin>>s>>t;
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;j<t.size();j++)
		{
			for(int k=1;k<=min(t.size()-j,s.size()-i);k++)
			{
				string u=s.substr(i,k),v=t.substr(j,k);
				if(u==v)
				{
					if(u.size()>=maxx)
					{
						maxx=u.size();
						p=u;
					}
				}
			}
		}
	}
	cout<<maxx<<endl;
	cout<<p<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}