#include <iostream>
#include <string.h>
using namespace std;
int prime[110];
void fun()
{
	for(int i=1;i<=100;i++)
	prime[i]=i;
	for(int i=2;i<=100;i++)
	{
		for(int j=2;j<=i-1;j++)
		{
			if(prime[i]%prime[j]==0)
			prime[i]/=prime[j];
		}
	}
}
int num[110],len;
int main ()
{
	int n;
	fun();
	while(cin>>n)
	{
		memset(num,0,sizeof(num));
		num[1]=1,len=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=len;j++)
			{
				num[j]*=prime[i];
			}
			for(int j=1;j<=len;j++)
			{
				num[j+1]+=num[j]/10;
				num[j]%=10;
			}
			while(num[len+1])
			{
				len++;
				num[len+1]=num[len]/10;
				num[len]%=10;
			}	
		}
		for(int i=len;i>=1;i--)
		{
			cout<<num[i];
		}
		cout<<endl;
	}
	return 0;
}