#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve()
{
	cin>>n>>s;
	int res1=0,res2=0,pos1=0,pos2=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='L') res1++;
		else res2++;
	}
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='L') pos1++;
		else pos2++;
		if(pos1!=res1-pos1&&pos2!=res2-pos2)
		{
			cout<<i+1<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}