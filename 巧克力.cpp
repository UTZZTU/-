#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,r,n;
    int isprime[1010];
    memset(isprime,0,sizeof(isprime));
    isprime[2]=isprime[3]=1;
    for(i=2;i<=1000;i++){
        if(isprime[i]){
            for(j=i+3;j<=1000;j+=3){
                isprime[j]=1;
            }
        }
    }
    scanf("%d",&r);
    for(i=1;i<=r;i++)
    {
    	scanf("%d",&n);
    	if(isprime[n])
    	printf("YES");
    	else
    	printf("NO");
    	if(i!=r)
    	printf("\n");
	}
    return 0;
}
