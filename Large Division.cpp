#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string a;
	int n;
	long long b;
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
			long long  sum1=0;
			for(int j=0;j<a.length();j++)
			{
				if(a[j]=='-')
				continue;
				sum1=sum1*10+a[j]-'0';
				sum1%=b;
			}
			if(sum1==0)
			printf("Case %d: divisible\n",i);
			else
			printf("Case %d: not divisible\n",i);
	}
	return 0;
}