#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res1,res2,n,k1,k2,f1[5000010],f2[5000010];
void sum(ll x)
{
	k1=0,k2=0;
	while(x&&x%2==0)
	{
		x/=2;
		k1++;
	}
	while(x&&x%5==0)
	{
		x/=5;
		k2++;
	}
}
int main ()
{
	cin>>n;
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	for(ll i=2;i<=n;i++)
	{
		sum(4*i-2);
		res1+=k1,res2+=k2;
		sum(i+1);
		res1-=k1,res2-=k2;
		f1[i]=res1,f2[i]=res2;
		f1[i]+=f1[i-1];
		f2[i]+=f2[i-1];
	}
	cout<<min(f1[n],f2[n]);
	return 0;
}