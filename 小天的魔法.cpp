#include <bits/stdc++.h>
using namespace std;
int n,m,x,a,b,cnt;
int main ()
{
	priority_queue<int> p1,p2;
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		p1.push(a);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b;
		p2.push(b);
	}
	while(!p2.empty()&&!p1.empty())
	{
		if(p2.empty()||p2.top()==0)
		{
			if(x>0)
			{
				cout<<-1;
				return 0;
			}
			else
			{
				cout<<cnt;
				return 0;
			}
		}
		else
		{
			if(p2.top()>=x)
			{
				cnt++;
				x-=p2.top();
				p2.pop();
			}
			else
			{
				if(p1.empty()||p1.top()==1)
				{
					cnt++;
					x-=p2.top();
					p2.pop();
				}
				else
				{
					cnt+=2;
					x-=p2.top()*p1.top();
					p2.pop();
					p1.pop();
				}
			}
		}
		if(x<=0) break;
	}
	if(x>0) cout<<-1;
	else cout<<cnt;
	return 0;
}