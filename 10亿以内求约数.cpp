#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 15
int ans=0;
int p[N],cnt;
int main()
{
	int i,j,k;
	for(i=1;i<=1000000000;i++)
	{
		cnt=0;
		k=i;
		for(j=2;j*j<=k;j++)
		{
			if(k%j==0)
			{
				p[++cnt]=0;
				while(k%j==0)
				{
					p[cnt]++;
					k/=j;
				}
			}
		}
		if(k>1)p[++cnt]=1;
		int temp=1;
		for(j=1;j<=cnt;j++)
		{
			temp*=(p[j]+1);
		}
		if(ans<temp)
		{
			printf("%d : %d\n",i,ans=temp);
		}
		if(i%10000000==0)printf("%d at %d\n",temp,i);	
	}
	printf("%d\n",ans);
	system("pause");
	return 0;
}
