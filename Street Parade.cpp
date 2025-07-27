#include <iostream>
#include <stack>
using namespace std;
int main ()
{
	int n,ks=1,k;
	stack<int> p;
	while(cin>>n)
	{
		if(n==0)
		break;
		ks=1;
		for(int i=1;i<=n;i++)
	{
		cin>>k;
		if(k==ks)
		{
			ks++;
			while(!p.empty()&&p.top()==ks)
			{
				p.pop();
				ks++;
			}
		}
		else
		p.push(k);
	}
	if(p.empty())
	printf("yes\n");
	else
	printf("no\n");
	}
	return 0;
}