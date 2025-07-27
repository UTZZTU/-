#include <bits/stdc++.h>
using namespace std;
int t,n,ch[30];
string s;
int main ()
{
	cin>>t;
	while(t--)
	{
		memset(ch,0,sizeof ch);
		cin>>n;
		cin>>s;
		for(int i=0;i<n;i++)
		{
			ch[s[i]-'A']++;
		}
		int minn=0x3f3f3f3f;
		minn=min(minn,ch['A'-'A']);
		minn=min(minn,ch['C'-'A']/2);
		minn=min(minn,ch['E'-'A']);
		minn=min(minn,ch['P'-'A']);
		minn=min(minn,ch['T'-'A']);
		cout<<minn<<endl;
	}
	return 0;
}