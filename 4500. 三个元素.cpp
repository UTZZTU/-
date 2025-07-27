#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
	int bh,dx;
}s[3030];
bool cmp(node a,node b)
{
	return a.dx<b.dx;
}
int x,y=-1,z=-1;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i].dx);
		s[i].bh=i;
	}
	sort(s+1,s+1+n,cmp);
	x=1;
	for(int i=2;i<=n;i++)
	{
		if(y==-1)
		{
			if(s[i].dx>s[x].dx)
			y=i;
		}
		else if(z==-1)
		{
			if(s[i].dx>s[y].dx)
			{
				z=i;
				break;
			}
		}
		else
		break;
	}
	if(y==-1||z==-1)
	cout<<"-1 -1 -1";
	else
	cout<<s[x].bh<<" "<<s[y].bh<<" "<<s[z].bh;
	return 0;
}