#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main ()
{
	int t;
	cin>>t;
	stack<int> p;
	while(t--)
	{
		int n,x;
		scanf("%d",&n);
		if(n==1)
		{
			scanf("%d",&x);
			p.push(x);
		}
		else if(n==2)
		{
			if(!p.empty())
			p.pop();
		}
		else
		{
			if(!p.empty())
		printf("%d\n",p.top());
		else
		printf("Empty!\n");
		}
		
	}
	return 0;
}