#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
int a[30];
vector<int> p[30];
int main ()
{
	string r="move",b="onto",c="over",d="pile",e="quit",x,y;
	int n,i,j;
	cin>>n;
	getchar();
	for(i=0;i<n;i++)
	{
		a[i]=i;
		p[i].push_back(i);
	}
	while(cin>>x)
	{
		int u1,u2;
		if(x==e)
		break;
		else
		{
			cin>>u1>>y>>u2;
			if(x==r&&y==b&&a[u1]!=a[u2])
			{
				int wz;
				for(i=0;i<p[a[u2]].size()&&p[a[u2]][i]!=u2;i++)
				;
				wz=i+1;
				i++;
				for(i;i<p[a[u2]].size();i++)
				{
					p[p[a[u2]][i]].push_back(p[a[u2]][i]);
					a[p[a[u2]][i]]=p[a[u2]][i];
				}
				if(wz<p[a[u2]].size())
				p[a[u2]].erase(p[a[u2]].begin()+wz,p[a[u2]].begin()+p[a[u2]].size());
				for(i=0;i<p[a[u1]].size()&&p[a[u1]][i]!=u1;i++)
				;
				wz=i;
				i++;
				for(i;i<p[a[u1]].size();i++)
				{
					p[p[a[u1]][i]].push_back(p[a[u1]][i]);
					a[p[a[u1]][i]]=p[a[u1]][i];
				}
				p[a[u1]].erase(p[a[u1]].begin()+wz,p[a[u1]].end());
				a[u1]=a[u2];
				p[a[u2]].push_back(u1);
			}
			else if(x==r&&y==c&&a[u1]!=a[u2])
			{
				int wz;
				for(i=0;i<p[a[u1]].size()&&p[a[u1]][i]!=u1;i++)
				;
				wz=i;
				i++;
				for(i;i<p[a[u1]].size();i++)
				{
					p[p[a[u1]][i]].push_back(p[a[u1]][i]);
					a[p[a[u1]][i]]=p[a[u1]][i];
				}
				p[a[u1]].erase(p[a[u1]].begin()+wz,p[a[u1]].end());
				a[u1]=a[u2];
				p[a[u2]].push_back(u1);
			}
			else if(x==d&&y==b&&a[u1]!=a[u2])
			{
				int wz,wy;
				for(i=0;i<p[a[u2]].size()&&p[a[u2]][i]!=u2;i++)
				;
				wz=i+1;
				i++;
				for(i;i<p[a[u2]].size();i++)
				{
					p[p[a[u2]][i]].push_back(p[a[u2]][i]);
					a[p[a[u2]][i]]=p[a[u2]][i];
				}
				p[a[u2]].erase(p[a[u2]].begin()+wz,p[a[u2]].end());
				for(i=0;i<p[a[u1]].size()&&p[a[u1]][i]!=u1;i++)
				;
				wz=i;
				wy=a[u1];
				for(i;i<p[a[wy]].size();i++)
				{
					p[a[u2]].push_back(p[a[wy]][i]);
					a[p[a[wy]][i]]=a[u2];
				}
				p[a[wy]].erase(p[a[wy]].begin()+wz,p[a[wy]].end());
				
			}
			else if(x==d&&y==c&&a[u1]!=a[u2])
			{
				int wz,wy;
				for(i=0;i<p[a[u1]].size()&&p[a[u1]][i]!=u1;i++)
				;
				wz=i;
				wy=a[u1];
				for(i;i<p[wy].size();i++)
				{
					p[a[u2]].push_back(p[wy][i]);
					a[p[wy][i]]=a[u2];
				}
				p[wy].erase(p[wy].begin()+wz,p[wy].end());
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d:",i);
		for(j=0;j<p[i].size();j++)
		printf(" %d",p[i][j]);
		printf("\n");
	}
	return 0;
}
