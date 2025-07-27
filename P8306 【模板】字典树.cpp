#include <bits/stdc++.h>
using namespace std;
int t[3000010][130],cnt[3000010],idx,T,n,q;
string s;
int get_num(char c)
{
	if(c>='A'&&c<='Z') return c-'A';
	else if(c>='a'&&c<='z') return c-'a'+26;
	return c-'0'+52;
}
void insert(string s,int v)
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		int x=get_num(s[i]);
		if(!t[p][x]) t[p][x]=++idx;
		p=t[p][x];
		cnt[p]+=v;
	}
}
int query(string s)
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		int x=get_num(s[i]);
		if(!t[p][x]) return 0;
		p=t[p][x];
	}
	return cnt[p];
}
int main ()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>q;
		getchar();
		while(n--)
		{
			cin>>s;
			insert(s,1);
		}
		while(q--)
		{
			cin>>s;
			cout<<query(s)<<endl;
		}
		for(int i=0;i<=idx;i++)
		{
			for(int j=0;j<=125;j++)
			{
				t[i][j]=0;
			}
		}
		for(int i=0;i<=idx;i++)
		{
			cnt[i]=0;
		}
		idx=0;
	}
	return 0;
}