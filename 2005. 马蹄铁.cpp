#include <bits/stdc++.h>
using namespace std;
int maxx,n,dirx[4]={0,0,-1,1},diry[4]={1,-1,0,0},st[10][10];
vector<char> vec;
string a[10];
void dfs(int x,int y)
{
	int i=0,q=0,h=0;
	while(i<vec.size()&&vec[i]=='(')
	{
		q++;
		i++;
	}
	while(i<vec.size()&&vec[i]==')')
	{
		h++;
		i++;
	}
	if(q<=h)
	maxx=max(maxx,2*min(q,h));
	for(int j=0;j<4;j++)
	{
		int dx=dirx[j]+x,dy=diry[j]+y;
		if(!st[dx][dy]&&dx>=0&&dx<n&&dy>=0&&dy<n)
		{
			vec.push_back(a[dx][dy]);
			st[dx][dy]=1;
			dfs(dx,dy);
			vec.pop_back();
			st[dx][dy]=0;
		}
	}
}
int main ()
{
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	cin>>a[i];
	st[0][0]=1;
	vec.push_back(a[0][0]);
	dfs(0,0);
	cout<<maxx;
	return 0;
}