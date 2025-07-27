#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
int main ()
{
	ll n,m,i;
	stack<int> p;
	cin>>n>>m;
	if(m==1)
	{
		printf("[1,1]");
	}
	else if(m==2)
	{
		printf("[2,2]");
	}
	else
	{
		for(i=2;i<=floor(sqrt(m));i++)
		{
			if(m%i==0)
			{
				if(m/i!=i)
				p.push(m/i);
				if(i+m/i/2<=n&&i-m/i/2>=1)
				{
					printf("[%d,%d]\n",i-m/i/2,i+m/i/2);
				}
			}
		}
		while(!p.empty())
		{
			i=p.top();
			if(i+m/i/2<=n&&i-m/i/2>=1)
				{
					printf("[%d,%d]\n",i-m/i/2,i+m/i/2);
				}
				p.pop();
		}
		if(m&1)
		{
			printf("[%d,%d]\n",m/2,m/2+1);
		}
		
		printf("[%d,%d]",m,m);
	}
	return 0;
}