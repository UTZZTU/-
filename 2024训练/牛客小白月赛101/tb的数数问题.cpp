#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,f[1000010],c[1000010],res,ss[1000010];
//bool check(int x)
//{
//	for(int i=1;i*i<=x;i++)
//	{
//		if(x%i==0)
//		{
//			int j=x/i;
//			if(c[i]&&c[j]) ;
//			else return false;
//		}
//	}
//	return true;
//}
void solve()
{
	cin>>n;
	memset(ss,1,sizeof ss);
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		c[f[i]]=1;
	}
//	sort(f+1,f+1+n);
	for(int i=1;i<=1000000;i++)
	{
		if(c[i]) continue;
		for(int j=i;j<=1000000;j+=i)
		{
			ss[j]=0;
		}
//		if(f[i]==f[i-1]) continue;
//		else
//		{
//			if(check(f[i])) res++;
//		}
	}
	for(int i=1;i<=1000000;i++)
	{
		if(ss[i]) res++;
	}
	cout<<res<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}