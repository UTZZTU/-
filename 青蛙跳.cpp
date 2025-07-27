#include <stdio.h>
int main ()
{
	int n,i,x1,x2,y1,y2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
		if(x1>x2&&y1>=y2||x2>x1&&y2>=y1)
		printf("NO\n");
		else
		{
			if((x2-x1)%(y1-y2)==0)
			printf("YES\n");
			else
			printf("NO\n");
		}
	}
	return 0;
}