#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
typedef long long ll;
int js[9],mx=0;
bool pd(int n)
{
	memset(js,0,sizeof(js));
	if(n<=mx)
	return false;
	else
	{
		while(n!=0)
		{
			js[n%10-1]++;
			n/=10;
		}
		for(int i=0;i<9;i++)
		{
		if(js[i]!=1)
		return false;
		}
		return true;
	}
}
int main ()
{
	int a[9]={1,2,3,4,5,6,7,8,9};
	do
	{
		for(int i=1;i<9;i++)
		{
			int t=pow(10,i-1);
			ll sum1=0,sum2=0,sum3;
			int j;
			for(j=0;j<i;j++)
			{
				sum1+=a[j]*t;
				t/=10;
			}
			t=1;
			for(j;j<9;j++)
			{
				sum2+=a[j]*t;
				t*=10;
			}
			sum3=sum1*sum2;
			if(pd(sum3))
			mx=sum3;
		}
	}while(next_permutation(a,a+9));
	cout<<mx;
	return 0;
}