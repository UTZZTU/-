#include <bits/stdc++.h>
using namespace std;
int t,n,a,b;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		for(int i=1;i<=2*n;i++){
			if(i==a)
			printf("%d ",b);
			else if(i==b){
				printf("%d ",a);
			}else{
				printf("%d ",i);
			}
		}
		printf("\n");
	}
	return 0;
}