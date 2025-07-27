#include<stdio.h>
#include<string.h>
#include <string.h>
int main()
{
	int t,k;
	char a[200];
	scanf("%d",&t);
	while(t--){
		int i,j,l;
		scanf("%s %d",a,&k);
		int len=strlen(a);
		for(i=0;i<k;i++){
			for(j=0;j<len-1;j++){
				if(a[j]>a[j+1]){
					for(l=j;l<len-1;l++){
						a[l]=a[l+1];
					}
					break;
				}
			}
			len-=1;
		}
		for(i=0;i<strlen(a)-k;i++){
			if(i==0&&a[i]=='0'){
				continue;
			}
			printf("%d",a[i]-'0');
		}
		printf("\n");
	}
}
