#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
	int i,a[100010],n,sum[100010],s=0,q[100010];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
for(i=1;i<=n;i++)
{
int k=i;
int u=a[i];
while(a[k+1]==u)
{
k++;
}
if(k-i+1>1)
{
sum[++sum[0]]=long long(k-i+1);//sumǰ׺������
sum[sum[0]]=sum[sum[0]]*(sum[sum[0]]-1)%1000000007;//��ʽ
q[sum[0]]=q[sum[0]-1]+sum[sum[0]];//Ԥ����
}
i=k;
}
for(i=1;i<=sum[0];i++)
{
s=s+(long long)(sum[i]*(q[sum[0]]-q[i]));//ǰ׺�ʹ��ڴˣ�
s%=1000000007;
}
printf("%d",(s-1)%1000000007);

}
