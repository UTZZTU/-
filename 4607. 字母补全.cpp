#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;
int judge,ans;
string u;
int main ()
{
	cin>>u;
	if(u.size()<26)
	cout<<-1;
	else
	{
		int i=0;
		for(i;i<26;i++)
		{
			if(u[i]=='?')
			ans++;
			else
			mp[u[i]]++;
		}
		if(mp.size()+ans==26)
		{
			judge=1;
			int j=0;
			for(j;j<26;j++)
			{
				if(u[j]=='?')
				{
					for(int k=0;k<26;k++)
					{
						if(!mp.count('A'+k))
						{
							u[j]='A'+k;
							mp['A'+k]++;
							break;
						}
					}
				}
			}
			for(j;j<u.size();j++)
			{
				if(u[j]=='?')
				u[j]='A';
			}
		}
		if(!judge)
		{
			for(i;i<u.size()&&!judge;i++)
		{
			if(u[i]=='?')
			ans++;
			else
			mp[u[i]]++;
			if(u[i-26]=='?')
			ans--;
			else
			{
			mp[u[i-26]]--;
			if(mp[u[i-26]]==0)
			mp.erase(u[i-26]);
			}
			if(mp.size()+ans==26)
		{
			judge=1;
			int j=i-25;
			for(j;j<i+1;j++)
			{
				if(u[j]=='?')
				{
					for(int k=0;k<26;k++)
					{
						if(!mp.count('A'+k))
						{
							u[j]='A'+k;
							mp['A'+k]++;
							break;
						}
					}
				}
			}
			for(int k=0;k<j;k++)
			{
				if(u[k]=='?')
				u[k]='A';
			}
			for(int k=i+1;k<u.size();k++)
			{
				if(u[k]=='?')
				u[k]='A';
			}
		}
		}
		}
		if(judge)
	cout<<u;
	else
	cout<<-1;
	}
	return 0;
}