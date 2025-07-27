#include <bits/stdc++.h>
using namespace std;
int t,a,b;
vector<int> vec[10];
int get_pos(int x)
{
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			if(vec[i][j]==x) return i;
		}
	}
	return -1;
}
void move(int pos,int a,int b)
{
	int flag=0;
	vector<int> v;
	for(int i=0;i<vec[pos].size();i++)
	{
		if(vec[pos][i]==a) flag=1;
		if(!flag) v.push_back(vec[pos][i]);
		else vec[pos+b].push_back(vec[pos][i]);
	}	
	vec[pos]=v;
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		for(int i=1;i<=9;i++)
		{
			vec[i].clear();
		}
		vec[2].push_back(1);
		vec[3].push_back(2);
		vec[4].push_back(3);
		for(int i=1;i<=12;i++)
		{
			scanf("%d%d",&a,&b);
			int pos=get_pos(a);
			move(pos,a,b);
		}
		if(vec[9].size()!=3) puts("N");
		else puts("Y");
	}
	return 0;
}