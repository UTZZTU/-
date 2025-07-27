#include <iostream>
using namespace std;
typedef long long ll;
int n,w[1010],x[1010],maxx;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&w[i],&x[i]);
	}
	for(int i=1;i<=24;i++)
	{
		int res=0;
		for(int j=1;j<=n;j++)
		{
			if((x[j]+i)%24>=9&&(x[j]+i)%24<=18&&(x[j]+i+1)%24>=9&&(x[j]+i+1)%24<=18)
			{
				res+=w[j];
			}
		}
		maxx=max(maxx,res);
	}
	printf("%d",maxx);
	return 0;
}