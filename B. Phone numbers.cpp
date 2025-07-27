#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve()
{
	cin>>n;
	cin>>s;
	int i=0;
	for(i;;i++)
	{
		if((n-i*2)%3==0)
		{
			break;
		}
	}
	int j=(n-i*2)/3;
	for(int k=0;k<n;k++)
	{
		if(k!=0) cout<<"-";
		if(i)
		{
			i--;
			string u;
			u+=s[k];
			k++;
			u+=s[k];
			cout<<u;
		}
		else
		{
			j--;
			string u;
			u+=s[k];
			k++;
			u+=s[k];
			k++;
			u+=s[k];
			cout<<u;
		}
	}
	cout<<endl;
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