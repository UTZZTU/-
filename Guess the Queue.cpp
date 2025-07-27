#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main ()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		printf("Case %d:\n",i);
		int n;
		cin>>n;
			getchar();
		deque<int> d;
		while(n--)
		{
			int x;
			char s;
			int u;
			scanf("%d %c",&x,&s);
			if(x==1)
			{
				scanf("%d",&u);
				if(s=='B')
				{
					d.push_back(u);
				}
				else if(s=='F')
				{
					d.push_front(u);
				}
			}
			else if(x==2)
			{
				if(s=='B')
				{
					d.pop_back();
				}
				else if(s=='F')
				{
					d.pop_front();
				}
			}
			else if(x==3)
			{
				scanf("%d",&u);
				if(s=='D')
				{
					cout<<d[u-1]<<endl;
				}
				else if(s=='P')
				{
					for(int j=0;j<d.size();j++)
					{
						if(d[j]==u)
						{
							cout<<j+1<<endl;
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}