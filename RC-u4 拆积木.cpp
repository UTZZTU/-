#include <bits/stdc++.h>
using namespace std;
int n,m,f[1010][1010],flag,num,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},ff[1000010];
set<int> st;
map<int,pair<int,int>> mp;
bool check(int x,int y,int num)
{
	int k=x;
	while(k>=1)
	{
		if(ff[f[k][y]]==0) break;
		if(f[k][y]==x)
		;
		else 
		return false;
		k--;
	}
	return true;
}
bool judge(int x)
{
	queue<pair<int,int>> q;
	q.push({mp[x]});
	map<pair<int,int>,bool> mp1;
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		if(mp1[p])
		continue;
		mp1[p]=true;
		if(!check(p.first,p.second,x))
		return false;
		cout<<p.first<<" "<<p.second<<endl;
		for(int i=0;i<4;i++)
		{
			int tx=dx[i]+p.first,ty=dy[i]+p.second;
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&f[tx][ty]==x)
			{
				q.push({tx,ty});
			}
		}
	}
	return true;
}
int main ()
{
	
//	printf("Impossible");
	scanf("%d%d",&n,&m);
	for(int i=1;i<=1000000;i++)
	{
		ff[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&f[i][j]);
			st.insert(f[i][j]);
			if(mp.count(f[i][j]))
			;
			else
			mp[f[i][j]]={i,j};
		}
	}
	while(1)
	{
		flag=0;
		for(auto it=st.begin();it!=st.end();it++)
		{
			int tt=*it;
			if(ff[tt])
			{
				if(judge(tt))
				{
					ff[tt]=0;
					if(num)
					cout<<" ";
					cout<<tt;
					num++;
					flag=1;
					break;
//					flag=1;
				}
			}
		}
		if(flag==0)
		{
			if(num==st.size())
			{
				return 0;
			}
			else
			{
				if(num)
				cout<<" ";
				cout<<"Impossible";
				return 0;
			}
		}
	}
	
	return 0;
}

/*
5 5
4 4 4 11 11
9 9 4 2 1
9 5 4 4 4
7 3 3 6 10
8 8 8 10 10

4 3
8 9 7
4 4 4
5 6 4
1 4 4
*/

