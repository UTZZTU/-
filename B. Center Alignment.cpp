#include <bits/stdc++.h>
using namespace std;
string s[1010];
int maxx,pos=1,cnt;
void solve()
{
	while(getline(cin,s[++cnt]))
	{
		maxx=max(maxx,(int)s[cnt].size());
	}
	cnt--;
	for(int i=1;i<=maxx+2;i++) cout<<"*";
	cout<<endl;
	for(int i=1;i<=cnt;i++)
	{
		cout<<"*";
		if(s[i].size()==0)
		{
			for(int j=1;j<=maxx;j++)
			{
				cout<<" ";
			}
		}
		else
		{
			int pp=maxx-(int)s[i].size();
			if(pp&1)
			{
				if(pos&1)
				{
					for(int j=1;j<=pp/2;j++)
					{
						cout<<" ";
					}
					cout<<s[i];
					for(int j=1;j<=(pp+1)/2;j++)
					{
						cout<<" ";
					}
				}
				else
				{
					for(int j=1;j<=(pp+1)/2;j++)
					{
						cout<<" ";
					}
					cout<<s[i];
					for(int j=1;j<=(pp)/2;j++)
					{
						cout<<" ";
					}
				}
				pos++;
				pos%=2;
			}
			else
			{
				for(int j=1;j<=pp/2;j++)
				{
					cout<<" ";
				}
				cout<<s[i];
				for(int j=1;j<=pp/2;j++)
				{
					cout<<" ";
				}
			}
		}
		cout<<"*"<<endl;
	}
	for(int i=1;i<=maxx+2;i++) cout<<"*";
//	cout<<maxx<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}