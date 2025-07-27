#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,pos,num,pp,k=1;
void fj(ll x)
{
	while(x)
	{
		pos++;
		if(x&1) num++;
		x>>=1;
	}
}
int main ()
{
	cin>>n;
	if(n==0)
	{
		cout<<"0";
		return 0;
	}
	fj(n);
	pp+=(ll)pow((ll)2,pos-1);
	num--;
	for(int i=1;i<=num;i++)
	{
		pp+=k;
		k*=2;
	}
	cout<<n-pp;
	return 0;
}