#include <stdio.h>
#include <string.h>
int main ()
{
	int a,b,c,m[200],e;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		if(a==0&&b==0&&c==0)
		break;
		else
		{
			memset (m,0,sizeof(m));
		m[0]=a/b;
		a%=b;
		int i=1;
		while(i<=c)
		{
			a*=10;
			m[i++]=a/b;
			a%=b;
		}
		a*=10;
		e=a/b;
		if(e>=5)
		{
			m[c]++;
			for(i=c-1;i>=1;i--)
				if(m[i+1]==10)
				m[i]++;
			if(m[1]==10)
			m[0]++;
			for(i=c;i>=1;i--)
			if(m[i]==10)
			m[i]=0;
		}
		printf("%d.",m[0]);
		for(i=1;i<=c;i++)
		printf("%d",m[i]);
		printf("\n");
		}
	}
	return 0;
}
