#include <bits/stdc++.h>
using namespace std;
int n,a0,a1,b0,b1;
int gcd(int a,int b)
{
	return b? gcd(b,a%b):a;
}
int main ()
{
	scanf("%d",&n);
	while(n--)
	{
		int sum=0;
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		for(int i=1;i<=floor(sqrt(b1));i++)
		{
			if(b1%i==0)
			{
				if(gcd(i,a0)==a1&&(long long)i*b0/gcd(i,b0)==b1)
				sum++;
				if(i*i!=b1&&gcd(b1/i,a0)==a1&&(long long)b1/i*b0/gcd(b1/i,b0)==b1) //防止两个数一样而加重
				sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}