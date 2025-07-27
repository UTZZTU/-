#include<iostream>
#include<math.h> 
using namespace std;
int main()
{long long int n;
cin>>n;
long long int sum=0;
for(int i=1;i<=n;i++)
	{long long number=0;long long p=0;
	int k=i;int o=i;
		while(k>0)//获得此数字的位数。
		{
			k=k/10;
			number++;//number为此数字位数。
		}
		p=p+o*pow(10,number);//构造回文数的前半部分。
		number--;
		for(number;o>0;number--)//将前半部分颠倒，进行加和。
			{
				p=p+o%10*pow(10,number);
				o/=10;
			}
		sum+=p;
	}
	cout<<sum;
 } 