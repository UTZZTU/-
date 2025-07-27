#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int n;
int a[100000];
int main(void)
{
	 int sum; 
	 while(scanf("%d", &n)!=EOF)
	 {
	 	sum=0;
	 	for(int i=1;i<=n;i++)
	 	scanf("%d",&a[i]);
	 	
	 	sort(a+1,a+1+n);
	 	
	 	for(int i=1;i<n;i++)
	 	{
	 		if(a[i+1]-a[i]<1)
	 		{
	 			sum+=a[i]-a[i+1]+1;	   
				a[i+1]=a[i]+1;
					
			}
		 
		}
	 	printf("%d\n",sum);
	 }
return 0;
}