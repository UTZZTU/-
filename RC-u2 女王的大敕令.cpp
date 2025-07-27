#include <bits/stdc++.h>
using namespace std;
set<vector<int>>st;
int s,x,z,y,n1,n2,n3,n4,row,cal,d1,d2;
int vis[10][10];
vector<int> vec;
bool check1(int a,int b)
{
	if(a<1||a>5||b<1||b>5||a==z-n3||a==y+n4||b==s||b==x||vis[a][b])
	return false;
	else
	return true;
}
bool check2(int a,int b)
{
	if(a<1||a>5||b<1||b>5||a==z-n3||a==y+n4||b==s+n1||b==x-n2||vis[a][b])
	return false;
	else
	return true;
}
void dfs(int a,int b,int ans)
{
	if(a==row&&b==cal)
	{
		if(ans==2)
		{
			st.insert(vec);
			return;
		}
	}
	if(ans==2)
	return;
	if(ans==0)
	{
		for(int i=0;i<=d1;i++)
		{
			int j=d1-i;
			if(check2(a+i,b+j))
			{
				vec.push_back(a+i);
				vec.push_back(b+j);
				vis[a+i][b+j]=1;
				dfs(a+i,b+j,1);
				vis[a+i][b+j]=0;
				vec.pop_back();
				vec.pop_back();
			}
		    if(check2(a+i,b-j))
			{
				vec.push_back(a+i);
				vec.push_back(b-j);
				vis[a+i][b-j]=1;
				dfs(a+i,b-j,1);
				vis[a+i][b-j]=0;
				vec.pop_back();
				vec.pop_back();
			}
			if(check2(a-i,b+j))
			{
				vec.push_back(a-i);
				vec.push_back(b+j);
				vis[a-i][b+j]=1;
				dfs(a-i,b+j,1);
				vis[a-i][b+j]=0;
				vec.pop_back();
				vec.pop_back();
			}
			if(check2(a-i,b-j))
			{
				vec.push_back(a-i);
				vec.push_back(b-j);
				vis[a-i][b-j]=1;
				dfs(a-i,b-j,1);
				vis[a-i][b-j]=0;
				vec.pop_back();
				vec.pop_back();
			}
		}
	}
	else
	{
		
		if(abs(a-row)+abs(b-cal)==d2)
		dfs(row,cal,2);
		else
		return;
	}
}
int main ()
{
	cin>>s>>x>>z>>y;
	cin>>n1>>n2>>n3>>n4;
	cin>>row>>cal>>d1>>d2;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(i==row&&cal==j||!check1(i,j))
			continue;
			memset(vis,0,sizeof(vis));
			vec.push_back(i);
			vec.push_back(j);
			vis[i][j]=1;
			dfs(i,j,0);
			vis[i][j]=0;
			vec.clear();
		}
	}
	for(auto it=st.begin();it!=st.end();it++)
	{
		vec=*it;
		for(int i=0;i<vec.size();i++)
		{
			if(i!=0)
			cout<<" ";
			cout<<vec[i];
		}
		cout<<endl;
	}
	return 0;
}