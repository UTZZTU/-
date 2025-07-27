#include <bits/stdc++.h>
using namespace std;
int n,q,u,v,w,val,pd;
int main ()
{
	while(scanf("%d %d",&n,&q)!=EOF)
	{
		deque<int> p[n+1];
		while(q--)
		{
			scanf("%d",&pd);
			if(pd==1)
			{
				scanf("%d %d %d",&u,&w,&val);
				if(w==0)
				p[u].push_front(val);
				else if(w==1)
				p[u].push_back(val);
			}
			else if(pd==2)
			{
				scanf("%d %d",&u,&w);
				if(p[u].empty())
				{
					printf("-1\n");
				}
				else
				{
					if(w==0)
					{
						printf("%d\n",p[u].front());
						p[u].pop_front();
					}
					else if(w==1)
					{
						printf("%d\n",p[u].back());
						p[u].pop_back();
					}
				}
			}
			else if(pd==3)
			{
				scanf("%d %d %d",&u,&v,&w);
				if(!p[v].empty())
				{
					if(w==0)
					{
						while(!p[v].empty())
						{
							p[u].push_back(p[v].front());
							p[v].pop_front();
						}
					}
					else if(w==1)
					{
						while(!p[v].empty())
						{
							p[u].push_back(p[v].back());
							p[v].pop_back();
						}
					}
				}
			}
		}
	}
	return 0;
	
}