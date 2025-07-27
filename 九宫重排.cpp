#include <bits/stdc++.h>
using namespace std;
struct node
{
	string str;
	int count;
	int x;
	int y;
};
string a,b;
set<string> s;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int bfs(int n)
{
	queue<node> que;
	node no;
	no.count=0;
	no.str=a;
	no.x=n/3;
	no.y=n%3;
	que.push(no);
	while(!que.empty())
	{
		for(int i=0;i<4;i++)
		{
			int xx=que.front().x+dx[i];
			int yy=que.front().y+dy[i];
			if(xx>=0&&xx<3&&yy>=0&&yy<3)
			{
				string u=que.front().str;
				int idex=que.front().x;
				int idey=que.front().y;
				int cnt=que.front().count+1;
				swap(u[xx*3+yy],u[idex*3+idey]);
				if(u==b)
				return cnt;
				if(s.count(u)==0)
				{
					s.insert(u);
					node nwe;
					nwe.str=u;
					nwe.count=cnt;
					nwe.x=xx;
					nwe.y=yy;
					que.push(nwe);
				}
			}
		}
		que.pop();
	}
	return -1;
}
int main ()
{
	cin>>a>>b;
	for(int i=0;i<9;i++)
	{
		if(a[i]=='.')
		cout<<bfs(i);
	}
	return 0;
}