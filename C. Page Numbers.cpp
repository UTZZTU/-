#include <bits/stdc++.h>
using namespace std;
string s;
set<int> st;
void solve()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		int num=0;
		int j=i;
		while(j<s.size()&&s[j]>='0'&&s[j]<='9')
		{
			num=num*10+(s[j]-'0');
			j++;
		}
		st.insert(num);
		i=j;
	}
	int l=-1,r=-1;
	for(auto x:st)
	{
		if(l==-1)
		{
			l=x,r=x;
		}
		else
		{
			if(x==r+1)
			{
				r=x;
			}
			else
			{
				if(l==r) cout<<l<<",";
				else
				cout<<l<<"-"<<r<<",";
				l=x,r=x;
			}
		}
	}
	if(r==l) cout<<l<<endl;
	else cout<<l<<"-"<<r<<endl;
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