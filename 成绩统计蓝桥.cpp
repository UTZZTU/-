#include <stdio.h>
#include <math.h>
int main ()
{
  int n,k,sum1=0,sum2=0,w1,w2,i;
  double s1,s2;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
  scanf("%d",&k);
  if(k>=60)
  sum1++;
  if(k>=85)
  sum2++;
}
s1=sum1*1.0/n*100;
w1=floor(s1+0.5);
s2=sum2*1.0/n*100;
w2=floor(s2+0.5);
printf("%d%%\n",w1);
printf("%d%%",w2);
return 0;
}