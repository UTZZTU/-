#include <bits/stdc++.h>
using namespace std;
string s;
int n;
void solve()
{
	cin>>n;
	cin>>s;
	int maxx=0,cnt=0;
	for(int i=0;i<n;i++)
	{
		cnt=1;
		int j=i+1;
		while(j<n&&s[j]==s[i]) 
		{
			cnt++;
			j++;
		}
		j--;
		maxx=max(maxx,cnt);
		i=j;
	}
	cout<<maxx+1<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}