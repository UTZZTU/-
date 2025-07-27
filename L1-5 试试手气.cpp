#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int a[1010],b[1010];
int main ()
{
    vector<int >o;
    stack<int> sg;
    int n,m,k,ks=1,q=-1,rl=0,pd=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(q==-1)
        {
        	if(sg.empty())
        	{
        		o.push_back(a[i]);
        	q=a[i];
        	rl++;
			}
        	else
        	{
        		o.push_back(sg.top());
        		q=sg.top();
        		sg.pop();
        		rl++;
        		if(a[i]<=q)
        		{
        			o.push_back(a[i]);
        			q=a[i];
        			rl++;
				}
				else
				sg.push(a[i]);
			}
		}
		else
		{
			if(sg.empty())
			{
				if(a[i]<=q)
				{
					rl++;
					q=a[i];
					o.push_back(a[i]);
					if(rl==k)
					{
						for(auto it=o.begin();it!=o.end();it++)
						{
							if(it!=o.begin())
							printf(" ");
							cout<<*it;
						}
						o.clear();
						q=-1;
						rl=0;
						printf("\n");
					}
				}
				else
				{
					sg.push(a[i]);
				}
			}
			else
			{
				while(!sg.empty()&&sg.top()<=q&&rl<k)
				{
					q=sg.top();
					o.push_back(sg.top());
					rl++;
					sg.pop();
				}
				if(rl==k)
				{
					for(auto it=o.begin();it!=o.end();it++)
						{
							if(it!=o.begin())
							printf(" ");
							cout<<*it;
						}
						o.clear();
						q=-1;
						rl=0;
						printf("\n");
				}
				if(q==-1)
				{
					o.push_back(a[i]);
        	q=a[i];
        	rl++;
				}
				else
				{
					if(a[i]<=q&&rl<k)
					{
						q=a[i];
						o.push_back(a[i]);
						rl++;
		            if(rl==k)
					{
						for(auto it=o.begin();it!=o.end();it++)
						{
							if(it!=o.begin())
							printf(" ");
							cout<<*it;
						}
						o.clear();
						q=-1;
						rl=0;
						printf("\n");
					}
					}
					else
					{
						if(sg.size()<m)
						{
							sg.push(a[i]);
						}
						else
						{
							for(auto it=o.begin();it!=o.end();it++)
						{
							if(it!=o.begin())
							printf(" ");
							cout<<*it;
						}
						o.clear();
						q=-1;
						rl=0;
						printf("\n");
						i--;
						}
					}
				}
			}
		}
    }
    while(!sg.empty())
    {
    	printf("%d",sg.top());
    	if(sg.size()!=1)
    	printf(" ");
    	sg.pop();
	}
    return 0;
}
