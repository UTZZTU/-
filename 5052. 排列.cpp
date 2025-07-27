#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,res=1,judge,sum,xz;
set<ll> st;
void dfs(ll num)
{
	if(num>n) return;
	st.insert(num);
	dfs(num*10+4);
	dfs(num*10+7);
}
ll get_num(ll x)
{
	ll o=0,i=0,fac=1,tt=k,lt;
	o=(n-xz),i+=(n-xz);
	if(x<=i) return x;
	i++;
	for(ll j=1;j<xz;j++) fac*=j;
	lt=xz-1;
	vector<ll> vec;
	for(ll j=i;j<=i+xz-1;j++)
	{
		vec.push_back(j);
	}
	for(i;i<=x;i++)
	{
		int pos=max(0,(int)ceil(tt*1.0/fac)-1);
		o=vec[pos];
//		printf("%d\n",pos);
//		printf("i: %d\n",i);
//		printf("o: %d\n",o);
		vector<ll> v;
		for(int j=0;j<vec.size();j++)
		{
			if(j==pos) continue;
			v.push_back(vec[j]);
		}
		vec=v;
		if(i==x) continue;
		tt-=fac*pos;
		fac/=lt;
		lt--;
	}
	return o;
}
bool pd(ll x)
{
	ll t=get_num(x);
	while(t)
	{
		if(t%10!=4&&t%10!=7) return false;
		t/=10;
	}
	return true;
}
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		res=res*i;
		if(res>=k)
		{
			judge=1;
			xz=i;
			break;
		}
	}
	if(!judge)
	{
		printf("-1");
		return 0;
	}
	ll num=0;
	dfs(num);
	for(auto it=st.begin();it!=st.end();it++)
	{
		if(*it!=0&&pd(*it)) sum++;
	}
	printf("%lld",sum);
	return 0;
}

//7 6 5 4 3 2 1