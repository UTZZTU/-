#include <iostream>
#include <deque>
using namespace std;
int main ()
{
	deque<int> a;
	int n,i,d,x,p,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k==0)
		{
			scanf("%d%d",&d,&x);
			if(d==0)
			a.push_front(x);
			else
			a.push_back(x);
		}
		else if(k==1)
		{
			scanf("%d",&p);
			printf("%d\n",a[p]);
		}
		else
		{
			scanf("%d",&d);
			if(d==0)
			a.pop_front();
			else
			a.pop_back();
		}
	}
	return 0;
}