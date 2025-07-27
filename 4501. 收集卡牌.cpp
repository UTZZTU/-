#include <bits/stdc++.h>
using namespace std;
struct node
{
	int xh,cz;
};
map<int,int> mp;
int n,m;
string u;
int main ()
{
	scanf("%d %d",&n,&m);
	for(int i=1,k;i<=m;i++)
	{
		scanf("%d",&k);
		mp[k]++;
		if(mp.size()<n)
		u+='0';
		else
		{
			map<int,int>::iterator it=mp.begin();
			for(;it!=mp.end();)
			{
				if((*it).second==1)
				mp.erase(it++);
				else
				{
					(*it).second--;
					++it;
				}
			}
			u+='1';
		}
	}
	cout<<u;
	return 0;
}