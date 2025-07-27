#include <stdio.h>
int main ()
{
	int x,y;
	while(scanf("%d %d",&x,&y)!=EOF)
	{
		int w=2,m=x,s;
		if(x==0&&y==0)   break;
		else
		{ 
			for(int i=x;i<=y;i++)
			{
				s=i*i+i+41;
			for(int a=2;a<s;a++)
			{
				if(s%a==0)
				break;
				else
				w++;
				
			}if(w==s)
				m++;
			
			}
			if(m==y)
			printf("OK\n");
			else  printf("Sorry\n");
		}
	}
	return 0;
}
