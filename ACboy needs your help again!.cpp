#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main ()
{
	int t;
	cin>>t;
	string a="FIFO",b="FILO",c,d="IN",e="OUT",f;
	int n;
	while(t--)
	{
		cin>>n;
		cin>>c;
		if(c==a)
		{
			queue<int> p;
			for(int i=1;i<=n;i++)
			{
				cin>>f;
				if(f==d)
				{
					int x;
					cin>>x;
					p.push(x);
				}
				else if(f==e)
				{
					if(p.empty())
					{
						printf("None\n");
					}
					else
					{
						printf("%d\n",p.front());
						p.pop();
					}
				}
			}
		}
		else if(c==b)
		{
			stack<int> p;
			for(int i=1;i<=n;i++)
			{
				cin>>f;
				if(f==d)
				{
					int x;
					cin>>x;
					p.push(x);
				}
				else if(f==e)
				{
					if(p.empty())
					{
						printf("None\n");
					}
					else
					{
						printf("%d\n",p.top());
						p.pop();
					}
				}
			}
		}
	}
	return 0;
}