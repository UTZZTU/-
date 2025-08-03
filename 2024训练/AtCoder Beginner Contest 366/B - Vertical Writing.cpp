#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s[100];
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;;i++)
	{
		int pos=-1;
		for(int j=n-1;j>=0;j--)
		{
			if(s[j].size()>=i)
			{
				pos=j;
			}
		}
		if(pos==-1) break;
		for(int j=n-1;j>=0;j--)
		{
			if(j>=pos)
			{
				if(s[j].size()>=i)
				{
					cout<<s[j][i-1];
				}
				else cout<<"*";
			}
			else cout<<" ";
		}
		cout<<endl;
	}
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