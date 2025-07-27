#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int t;
	cin>>t;
	string a="IN",b="OUT";
	while(t--)
	{
		priority_queue<int> p;
		int n,i,k;
		cin>>n;
		getchar();
		string x;
		for(i=1;i<=n;i++)
		{
			cin>>x;
			if(x==a)
			{
				cin>>k;
				p.push(k);
			}
			else if(x==b)
			{
				if(!p.empty())
				{
					printf("%d\n",p.top());
					p.pop();
				}
				else
				printf("EMPTY\n");
			}
		}
	}
	return 0;
}