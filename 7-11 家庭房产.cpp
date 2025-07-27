#include<stdio.h>
#include<string.h>
int a[1010][100],n;
void putfun(int a[][2],double b[][2],int m,int j)
{
    int i,t;
    for(i=1;i<m;i++)
    {
	    if(b[i][1]>b[j][1]&&b[i][1]!=-1)j=i;
		else if(b[i][1]==b[j][1]&&a[i][1]>a[j][1])j=i;
		   
	}
	printf("%04d %d %.3lf %.3lf\n",a[j][0],a[j][1],b[j][0],b[j][1]);
	b[j][1]=-1;
}
int rfun(int a[],int s)
{
    int i,j,k; 
    for(i=0;i<s;i++)
      for(j=i+1;j<s;j++)
        if(a[j]==a[i])
        {
          for(k=j+1;k<s;k++)a[k-1]=a[k];
          s--;
        }   
    return s;
}
void pfun(int num,int k)
{
   int i,j,x;
   for(i=0;i<n;i++)
     for(j=2;j<a[i][1]-2;j++)
	    if(a[i][j]==num&&j!=5&&a[i][j]!=-1&&a[i][0]==0)
		{	 
		    a[i][0]=k;
            for(x=2;x<a[i][1]-2;x++)
	          if(x!=5&&a[i][x]!=-1)pfun(a[i][x],k);
		}
}
int main()
{
    int i,j,count,k=0,min=10000,s,sumF,sumS;
    int rnum[1010],ren[1010][2];
    double ave[1010][2];
	scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       j=0;	
       a[i][0]=0;
	   scanf("%d %d %d",&a[i][2],&a[i][3],&a[i][4]);
	   scanf("%d",&a[i][5]); 
	   j=6;
	   count=a[i][5];
	   while(count)
	   {
	      scanf("%d",&a[i][j++]);
	      count--;
	   } 
	   scanf("%d %d",&a[i][j],&a[i][j+1]);
	   a[i][1]=j+2;
    }
    k=0;
    for(i=0;i<n;i++)if(a[i][0]==0){k++;pfun(a[i][2],k);}
    printf("%d\n",k);
    for(count=1;count<=k;count++)
	{
	  min=10000;
	  memset(rnum,0,sizeof(rnum)); 
	  sumF=sumS=s=0;
      for(i=0;i<n;i++)
      {
	    if(a[i][0]==count)
	    {
		   for(j=2;j<a[i][1]-2;j++)
	          if(j!=5&&a[i][j]!=-1)
	          {
	             if(a[i][j]<min)min=a[i][j];
	             rnum[s++]=a[i][j];
	          }
	          sumF+=a[i][a[i][1]-2];
	          sumS+=a[i][a[i][1]-1];
		}
      } 
 	  ren[count][0]=min;                   
 	  ren[count][1]=rfun(rnum,s);          
 	  ave[count][0]=sumF*1.0/ren[count][1];
 	  ave[count][1]=sumS*1.0/ren[count][1];
    }
    for(i=1;i<=k;i++)putfun(ren,ave,count,i);
    return 0;
}
