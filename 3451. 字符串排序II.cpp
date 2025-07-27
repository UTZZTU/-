#include <bits/stdc++.h>
using namespace std;
string u;
struct node
{
	int pos;
	int value;
	char c;
}s[1010];
int cnt,f[1010];
bool cmp(node a,node b)
{
	if(a.value!=b.value) return a.value<b.value;
	return a.pos<b.pos;
}
int main ()
{
	while(getline(cin,u))
	{
		cnt=0;
		string v;
		map<int,char> mp;
		memset(f,0,sizeof f);
		for(int i=0;i<u.size();i++)
		{
			if(u[i]>='a'&&u[i]<='z')
			{
				s[++cnt].pos=i;
				s[cnt].c=u[i];
				s[cnt].value=u[i]-'a';
			}
			else if(u[i]>='A'&&u[i]<='Z')
			{
				s[++cnt].pos=i;
				s[cnt].c=u[i];
				s[cnt].value=u[i]-'A';
			}
			else
			{
				f[i]=1;
				mp[i]=u[i];
			}
		}
		sort(s+1,s+1+cnt,cmp);
		int i=0,j=1;
		while(i<u.size())
		{
			if(f[i]) v+=mp[i];
			else 
			{
				v+=s[j].c;
				j++;
			}
			i++;
		}
		cout<<v<<endl;
	}
	return 0;
}