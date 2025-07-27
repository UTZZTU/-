#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
	int t,a[110];
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n,k,sum=0,i,x,y;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>k;
			a[i]=k+a[i-1];
		}
	  scanf("%d %d",&x,&y);
	  printf("%d\n",a[y]-a[x-1]);
	}
	return 0;
}