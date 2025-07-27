#include<stdio.h>
#include<string.h>
typedef struct n
{
	int hour;
	int m;
}time;
int solve(time a,int b,int c)
{
	return (b-a.hour)*60+c-a.m;
	
}
main()
{
	int n,num,a,b,flag[1002],sum,count;
	char c;
	time d[1005];
	scanf("%d",&n);
	for(int i=0;i<n;)
	{   sum=0;
	    count =0;
	    for(int j=0;j<1002;j++)flag[j]=0;
	    for(;scanf("%d %c %d:%d",&num,&c,&a,&b)&&num!=0;)
	   {
	   if(c=='E')
	   {
   		if(flag[num]==1)
	   	   {
		   sum+=solve(d[num],a,b);
		   
	       count++;
		   flag[num]=0;//未借 
		   }
       }	
       else {
       	 flag[num]=1;//借出 
       	 d[num].hour=a;
       	 d[num].m=b;
       }
	   }
   		i++;
   		if(count!=0)
   		printf("%d %d\n",count,(int)(1.0*sum/count+0.5));
   		else printf("0 0\n");
	   
	}
	
}