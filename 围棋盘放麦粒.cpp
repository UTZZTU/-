#include<stdio.h>
void multi2(int a[])
{
int carry=0,i; 
 for(i=999;i>=0;i--){
  int tmp=a[i]*2;
  a[i]=tmp%10+carry;
   carry=tmp/10;
}
}
void plus(int sum[],int add[])
{
int carry=0;//��λ
int i;
for(i=999;i>=0;i--){
int tmp=sum[i]+add[i];
sum[i]=tmp%10+carry;
carry=tmp/10;
}
}
int main()
{
int sum[1000]={0};
int add[1000]={0};
int n,i;
scanf("%d",&n);
add[999]=1;//�趨��λ
for(i=0;i<n;i++)
{
plus(sum,add);
multi2(add);
}
int k;
for(i=0;i<1000;i++)
{
if(sum[i]!=0){
k=i;//��һ����Ϊ0�Ŀ�ʼ�����
break;
}
}
for(i=k;i<1000;i++){
printf("%d",sum[i]);
}
printf("\n");
return 0;
}

