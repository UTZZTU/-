#include <stdio.h>
int main ()
{
   int a,b,n,i,js=0,min,w[1000],m,j,pd=0;
   char s1,s2;
   scanf("%c %d",&s1,&a);
   scanf("%d",&n);
   getchar();
   min=20;
   m=0;
   for(i=1;i<=n;i++)
   {
   	scanf("%c %d",&s2,&b);
   	getchar();
   	if(b==1)
   	b=14;
   	if(s2==s1)
   	{
   		if(b>a)
   		{
   			for(j=0;j<m;j++)
   			{
   				if(b==w[j])
   				{
   					pd=1;
   					break;
				   }
			   }
			   if(pd==0)
			   {
			   	js++;
			   	w[m]=b;
			   	m++;
			   }
   			if(b<min)
   			min=b;
		   }
	   } 
   }
   if(js==0)
   printf("0");
   else
   {
   	printf("%d\n",js);
   	if(min>=2&&min<=10)
   	printf("%c %d",s1,min);
   	else if(min==11)
   	printf("%c Jack",s1);
   	else if(min==12)
   	printf("%c Queen",s1);
   	else if(min==13)
   	printf("%c King",s1);
   	else
   	printf("%c Ace",s1);
   }
    return 0;
}
