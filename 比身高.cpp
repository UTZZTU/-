#include<cstdio>
using namespace std;
int i,j,k,s=0,t1,t2,n,a[1001];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	 for(i=1;i<=n;i++)
	 {
	 	t1=t2=0;
	 	for(j=1;j<i;j++)
	 	{
	 		if(a[j]>a[i])
	 			t1++;
		}
		 for(k=i+1;k<=n;k++)
		 {
		 	if(a[k]>a[i])
		 		t2++;		 
		 }
		 if(t1==t2)
		 s++;
	 }
	 printf("%d",s);
	 return 0;
 } 