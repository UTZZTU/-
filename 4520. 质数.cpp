#include <bits/stdc++.h>
using namespace std;
int t;
bool judge(int n)
{
	if(n==2||n==3)
	return true;
	if(n%6!=1&&n%6!=5)
	return false;
	else
	{
		for(int i=5;i<=floor(sqrt(n));i+=6)
		{
			if(n%i==0||n%(i+2)==0)
			return false;
		}
		return true;
	}
}
int len(int x)
{
	int l=0;
	while(x)
	{
		x/=10;
		l++;
	}
	return l;
}
int add(int x)
{
	int sum=1,num;
	num=x*pow(10,len(sum))+sum;
	while(!judge(num))
	{
		sum++;
		num=x*pow(10,len(sum))+sum;
	}
	return num;
}
int main ()
{
	cin>>t;
	for(int i=1,k;i<=t;i++)
	{
		cin>>k;
		cout<<add(k)<<endl;
	}
	return 0;
}