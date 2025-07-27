#include <bits/stdc++.h>
using namespace std;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	deque<int> q;
	while(n--)
	{
		int x,y;
		cin>>x;
		if(x==1)
		{
			cin>>y;
			q.push_front(y);
		}
		else if(x==2)
		{
			cin>>y;
			q.push_back(y);
		}
		else if(x==3)
		{
			if(!q.empty())
			{
				printf("%d\n",q.front());
				q.pop_front();
			}
		}
		else
		{
			if(!q.empty())
			{
				printf("%d\n",q.back());
				q.pop_back();
			}
		}
	}
	return 0;
}