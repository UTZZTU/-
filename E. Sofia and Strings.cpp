#include <bits/stdc++.h>
using namespace std;
int t,n,m,flag;
string s,tt;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		flag=1;
		set<int> st[30];
		scanf("%d%d",&n,&m);
		getchar();
		cin>>s>>tt;
		for(int i=0;i<s.size();i++)
		{
			st[s[i]-'a'].insert(i);
		}
		for(int i=0;i<tt.size();i++)
		{
			int c=tt[i]-'a';
			if(st[c].empty())
			{
				flag=0;
				break;
			}
			else
			{
				int pos=*(st[c].begin());
				st[c].erase(st[c].begin());
				for(int j=0;j<c;j++)
				{
					while(st[j].size()&&*(st[j].begin())<pos)
					{
						st[j].erase(st[j].begin());
					}
				}
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}