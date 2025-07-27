#include <stdio.h>
#include <string.h>
int main ()
{
   int n,i,a[15],cc,mm,sum=0,min;
   memset(a,0,sizeof(a));
   char s1[10],s2[10],s3[10],s4[10],c,m;
   scanf("%s %s",s1,s2);
   c=s1[0];
   if(s2[1]>='0'&&s2[1]<='9')
   cc=s2[1]-'0'+10;
   else
   cc=s2[0]-'0';
   if(cc==1)
   cc=14;
   scanf("%d",&n);
   getchar();
   for(i=0;i<n;i++)
   {
   	scanf("%s %s",s3,s4);
   	m=s3[0];
   	if(s4[1]>='0'&&s4[1]<='9')
   	mm=s4[1]-'0'+10;
   	else
   	mm=s4[0]-'0';
   	if(mm==1)
   	mm=14;
   	if(c==m)
   	{
   		if(mm>cc)
   		{
   			a[mm]=1;
		   }
	   }
   }
   for(i=14;i>=0;i--)
   {
   	if(a[i]==1)
   	{
   		sum++;
   		min=i;
	   }
   	
   }
   if(sum==0)
   {
   	printf("0");
   }
   else
   {
   	printf("%d\n",sum);
   	printf("%c ",c);
   	if(min==14)
   		printf("Ace");
	   else if(min==13)
	   printf("King");
	   else if(min==12)
	   printf("Queen");
	   else if(min==11)
	   printf("Jack");
	   else
	   printf("%d",min);
	   
   }
    return 0;
}
