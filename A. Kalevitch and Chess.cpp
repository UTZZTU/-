#include <bits/stdc++.h>
using namespace std;
string s[10];
int h[10],l[10],sum;
void solve()
{
	for(int i=0;i<8;i++) cin>>s[i];
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(s[i][j]=='W')
			{
//				if(i-1>=0&&s[i-1][j]=='B'||i+1<8&&s[i+1][j]=='B') l[j]++;
//				if(j-1>=0&&s[i][j-1]=='B'||j+1<8&&s[i][j+1]=='B') h[i]++;
				h[i]++,l[j]++;
			}
		}
	}
	for(int i=0;i<8;i++)
	{
		if(!h[i]) sum++;
		if(!l[i]) sum++;
	}
	if(sum==16) sum=8;
	cout<<sum<<endl;
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