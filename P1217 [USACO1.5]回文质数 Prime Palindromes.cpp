#include <bits/stdc++.h>
using namespace std;
const int N = 1e8+10;
int primes[N],cnt,a,b;
bool st[N];
void init(int x)
{
	st[0]=true;
	st[1]=true;
	for(int i=2;i<=x;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=x;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0)
			break;
		}
	}
}
bool judge(int x)
{
	int y=x,num=0;
    while (y!=0)
    {
        num=num*10+y%10;
        y/=10;
    } 
    if (num==x) return 1;
    else return 0;
}
int main ()
{
	cin>>a>>b;
	init(min(b,10000000));
	for(int i=lower_bound(primes,primes+cnt,a)-primes;i<cnt;i++)
	{
		if(judge(primes[i]))
		cout<<primes[i]<<endl;
	}
	return 0;
}