#include <stdio.h>
#include <vector>
using namespace std;
int main ()
{
	int n,i,x,p,q;
	vector<int> a;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&q);
		if(q==0)
		{
			scanf("%d",&x);
			a.push_back(x);
		}
		else  if(q==1)
		{
			scanf("%d",&p);
			printf("%d\n",a[p]);
		}
		else if(q==2)
		{
			a.pop_back();
		}
	}
	return 0;
}
