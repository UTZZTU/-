#include <iostream>
#include <string.h>
using namespace std;
int a[25][25];
int main ()
{
   int n;
   while(cin>>n)
   {
   	memset(a,0,sizeof(a));
   	 int i=1,j=1,sum=1;
   	 while(sum<=n*n)
   	 {
   	 	while(i<=n&&a[i][j]==0)
   	 	{
   	 		a[i][j]=sum;
   	 		sum++;
   	 		i++;
			}
   	 	i--;
   	 	j++;
   	 	while(j<=n&&a[i][j]==0)
   	 	{
   	 		a[i][j]=sum;
   	 		sum++;
   	 		j++;
			}
			j--;
			i--;
			while(i>=1&&a[i][j]==0)
   	 	{
   	 		a[i][j]=sum;
   	 		sum++;
   	 		i--;
			}
			i++;
			j--;
   	 	while(j>=1&&a[i][j]==0)
   	 	{
   	 		a[i][j]=sum;
   	 		sum++;
   	 		j--;
			}
			j++;
			i++;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%d",a[i][j]);
				if(j!=n)
				printf(" ");
			}
			printf("\n");
		}
   }
   return 0;
}