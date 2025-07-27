#include <iostream>
using namespace std;
int a[13];
int main()
{
int sum=0,i,j,xq,k;
a[1]=31;
a[3]=31;
a[4]=30;
a[5]=31;
a[6]=30;
a[7]=31;
a[8]=31;
a[9]=30;
a[10]=31;
a[11]=30;
a[12]=31;
xq=6;
for(i=2000;i<=2019;i++)
{
  if(i%4==0&&i%100!=0||i%400==0)
  a[2]=29;
  else
  a[2]=28;
  for(j=1;j<=12;j++)
  {
    for(k=1;k<=a[j];k++)
    {
      if(xq==1||k==1)
      sum+=2;
      else
      sum+=1;
      xq++;
      xq%=7;
    }
  }
}
if(i%4==0&&i%100!=0||i%400==0)
  a[2]=29;
  else
  a[2]=28;
for(j=1;j<=9;j++)
{
  for(k=1;k<=a[j];k++)
    {
      if(xq==1||k==1)
      sum+=2;
      else
      sum+=1;
      xq++;
      xq%=7;
    }
}
sum+=2;
printf("%d",sum);
  return 0;
}