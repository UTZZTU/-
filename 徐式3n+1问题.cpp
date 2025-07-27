#include<stdio.h>
int main()
{
    long long int i,j,k,m,n,a,b,c,s,r;
    while(scanf("%lld%lld",&m,&n)!=EOF)
    {
    long long int max=0;
    long long int num;
    if(m==0&&n==0)
    {
    printf("0 0 0\n");
    break;
}
s=m;
r=n;
    if(m>n)
    {
        c=m;
        m=n;
        n=c;
    }
    for(i=m;i<=n;i++)
    {
        num=1; 
        j=i;
        while(j>1)
        {
        if(j%2!=0)
        {
        j=3*j+1;
        num++;
        }
        else
        {
        j=j/2;
        num++;
        }
        }
    if(num>max)
    max=num;
    }
printf("%lld %lld %lld\n",s,r,max);
}
return 0;
}
