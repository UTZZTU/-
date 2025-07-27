#include <bits/stdc++.h>
using namespace std;
vector<int> G[10010];
int n,m,k;
int main ()
{
     deque<int> tsq;
     stack<int> box;
     cin>>n>>m>>k;
     for(int i=1,s;i<=n;i++)
     {
     	cin>>s;
     	tsq.push_back(s);
	 }
	 int i;
	 for(i=0;tsq.size()!=0||box.size()!=0;i++)
	 {
	 	int gs=0,sc=-1,flag=0;
	 	if(box.size()!=0)
	 	{
	 			sc=box.top();
	 			gs++;
	 			box.pop();
	 			G[i].push_back(sc);
			    while(box.size()!=0&&box.top()<=sc&&gs<k)
			    {
			    	sc=box.top();
	 			gs++;
	 			box.pop();
	 			G[i].push_back(sc);
				}
				if(gs==k)
				{
					continue;
				}
				while(gs<k)
				{
					if(tsq.size()==0)
					{
						flag=1;
						break;
					}
					else if(tsq.front()<=sc)
					{
						sc=tsq.front();
	 			        gs++;
	 			        tsq.pop_front();
	 			        G[i].push_back(sc);
					}
					else 
					{
						if(box.size()==m)
						{
							flag=1;
							break;
						}
						else
						{
							box.push(tsq.front());
							tsq.pop_front();
						}
					}
				}
				if(flag)
				continue;
				if(gs==k)
				{
					continue;
				}
		 }
		 else
		 {
		 	    sc=tsq.front();
	 			gs++;
	 			tsq.pop_front();
	 			G[i].push_back(sc);
	 			while(gs<k)
	 			{
					if(box.size()!=0&&box.top()<=sc)
					{
						sc=box.top();
	 			       gs++;
	 			        box.pop();
	 			       G[i].push_back(sc);
					}
					else if(tsq.size()==0)
					{
						flag=1;
						break;
					}
					else if(tsq.front()<=sc)
					{
						sc=tsq.front();
	 			        gs++;
	 			        tsq.pop_front();
	 			        G[i].push_back(sc);
	 			        while(box.size()!=0&&box.top()<=sc&&gs<k)
			        {
			    	sc=box.top();
	 			gs++;
	 			box.pop();
	 			G[i].push_back(sc);
				}
					}
					else 
					{
						if(box.size()==m)
						{
							flag=1;
							break;
						}
						else
						{
							box.push(tsq.front());
							tsq.pop_front();
						}
					}
				 }
				 if(flag)
				 continue;
				 if(gs==k)
				 continue;
		 }
	 }
	 for(int j=0;j<i;j++)
	 {
	 	for(int k=0;k<G[j].size();k++)
	 	{
	 		if(k!=0)
	 		cout<<" ";
	 		cout<<G[j][k];
		 }
		 cout<<endl;
	 }
	 return 0;
}