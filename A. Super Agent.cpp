#include <bits/stdc++.h>
using namespace std;
string s[3];
void solve()
{
	for(int i=0;i<3;i++) cin>>s[i];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(s[i][j]=='X')
			{
				int posx=2-i,posy=2-j;
				if(s[posx][posy]!='X')
				{
					cout<<"NO"<<endl;
					return;
				}
			}
		}
	}
	cout<<"YES"<<endl;
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