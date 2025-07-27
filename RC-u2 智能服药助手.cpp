#include <bits/stdc++.h>
using namespace std;
int n,m;
int timee[1010];
int main ()
{
	vector<int> p[1010];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>timee[i];
    for(int i=1,k,x,t;i<=m;i++)
    {
    	cin>>t;
    	cin>>k;
    	for(int j=1;j<=k;j++)
    	{
    		cin>>x;
    		if(timee[x]!=-1)
    		{
    			if(p[x].empty())
    			p[x].push_back(t);
    			else
    			{
    				int u=p[x].back();
    				if(t-u<timee[x])
    				{
    					printf("Don't take %d at %d!\n",x,t);
					}
					else
					p[x].push_back(t);
				}
			}
		}
	}
	return 0;
}