#include <bits/stdc++.h>
using namespace std;
int n,m,k;
deque<int> dq;
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		dq.push_back(k);
	}
	sort(dq.begin(),dq.end());
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	while(m--)
	{
		int front=dq.front(),back=dq.back();
		dq.pop_front();
		dq.pop_back();
		if(front==back)
		{
			cout<<0;
			return 0;
		}
		if(dq.empty())
		{
			cout<<0;
			return 0;
		}
		else
		{
			if(dq.back()-front<=back-dq.front())
			{
				dq.push_front(front);
				dq.push_front(front);
			}
			else
			{
				dq.push_back(back);
				dq.push_back(back);
			}
		}
	}
	int front=dq.front(),back=dq.back();
	cout<<back-front;
	return 0;
}