#include <bits/stdc++.h>
using namespace std;
int t,n,m,judge,a,b;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
//		judge=0;
//		if(n-m<=0)
//		{
//			printf("-1\n");
//		}
//		else
//		{
//			int x=n-m;
//			for(int i=1;i*i<=x;i++)
//			{
//				if(x%i==0)
//				{
//					b=i;
//					int k=x/i-1;
//					a=m+k*b;
//					if(a+b==n&&a>=0&&b>=1&&(a%b==m))
//					{
//						judge=1;
//						printf("%d %d\n",a,b);
//						break;
//					}
//					b=x/i;
//					k=i-1;
//					a=m+k*b;
//					if(a+b==n&&a>=0&&b>=1&&(a%b==m))
//					{
//						judge=1;
//						printf("%d %d\n",a,b);
//						break;
//					}
//				}
//			}
//			if(judge) continue;
//			else printf("-1\n");
//		}
        if(m*2>=n) printf("-1\n");
        else printf("%d %d\n",m,n-m);
	}
	return 0;
}