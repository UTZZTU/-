#include<stdio.h>
#include<stdbool.h>
#include <string.h>
#define n 10001000
bool number[n+1];
int prime[n+1];
int main(void){
    int count=0,i,j;
    memset(number,true,sizeof(number));
    for(i=2;i<=n;i++){
        if(number[i])   prime[count++]=i;
        for(j=0;j<count&&prime[j]*i<=n;j++){
            number[prime[j]*i]=false;
            if(i%prime[j]==0)	break;
        }
    }
    int t,x,h,q,l1,l2;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
    	scanf("%d",&x);
    	if(number[x]==true)
    	{
    		printf("%d",x);
		}
		else
		{
			for(j=x-1;j>=2;j--)
			{
				if(number[j]==true)
				{
					h=j;
					break;
				}
			}
			for(j=x+1;j<=n;j++)
			{
				if(number[j]==true)
				{
					q=j;
					break;
				}
			}
			l1=x-h;
			l2=q-x;
			if(l1<l2)
			printf("%d",h);
			else
			printf("%d",q);
		}
		if(i!=t)
		printf("\n");
	}
    return 0;
}

