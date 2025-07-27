#include <bits/stdc++.h>
using namespace std;
int t,n,m,q,p,r;
char l;
struct pp{
	vector<int> zy;
	queue<int> q;
};
struct rr{
	int zy;
	queue<int> q;
};
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>q;
		pp P[1010];
		rr R[1010];
		for(int i=0;i<=1000;i++)
		{
			R[i].zy=-1;
		}
		while(q--)
		{
			cin>>p>>l;
			if(l=='L')
			{
				cin>>r;
				if(R[r].zy==-1)
				{
					R[r].zy=p;
					int judge=0;
					for(int i=0;i<P[p].zy.size();i++)
					{
						if(P[p].zy[i]==r)
						{
							judge=1;
							break;
						}
					}
					if(!judge)
					P[p].zy.push_back(r);
					printf("%d: acquired: %d\n",p,r);
				}
				else if(R[r].zy==p)
				{
					printf("%d: already acquired: %d\n",p,r);
				}
				else
				{
					queue<int> qq;
					int judge=0;
					while(R[r].q.size())
					{
						qq.push(R[r].q.front());
						if(R[r].q.front()==p)
						{
							judge=1;
						}
						R[r].q.pop();
					}
					R[r].q=qq;
					if(judge)
					{
						printf("%d: already in pending: %d\n",p,r);
					}
					else
					{
						R[r].q.push(p);
						P[p].zy.push_back(r);
						printf("%d: pending: %d\n",p,r);
					}
				}
			}
			else
			{
				printf("%d: exiting\n",p);
				for(int i=P[p].zy.size()-1;i>=0;i--)
				{
					if(R[P[p].zy[i]].zy==p)
					{
						R[P[p].zy[i]].zy=-1;
						printf("%d: releasing: %d\n",p,P[p].zy[i]);
						if(R[P[p].zy[i]].q.empty())
					{
						printf("%d: no pending processes\n",P[p].zy[i]);
					}
					else
					{
						int x=R[P[p].zy[i]].q.front();
						R[P[p].zy[i]].q.pop();
						int judge=0;
						for(int i=0;i<P[x].zy.size();i++)
						{
							if(P[x].zy[i]==P[p].zy[i])
							{
								judge=1;
								break;
							}
						}
						if(!judge)
						P[x].zy.push_back(P[p].zy[i]);
						R[P[p].zy[i]].zy=x;
						printf("%d: acquired: %d\n",x,P[p].zy[i]);
					}
					}
					int judge=0;
					queue<int> qq;
					while(R[P[p].zy[i]].q.size())
					{
						int xx=R[P[p].zy[i]].q.front();
						R[P[p].zy[i]].q.pop();
						if(xx==p)
						judge=1;
						else
						qq.push(xx);
						
					}
					R[P[p].zy[i]].q=qq;
					if(judge)
					printf("%d: exit without acquiring: %d\n",p,P[p].zy[i]);
				}
				P[p].zy.clear();
			}
		}
	}
	return 0;
}