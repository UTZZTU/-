#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,f[200010];
int s1()
{
	int num=1,pos=0;
	while(1)
	{
		for(int i=1;i<=n;i++)
		{
			if(f[i]==num)
			{
				num++;
			}
		}
		if(num==n+1) break;
		else pos++;
	}
	return pos;
}
int s2()
{
	int num=1,pos=0;
	while(1)
	{
		for(int i=n;i>=1;i--)
		{
			if(f[i]==num)
			{
				num++;
			}
		}
		if(num==n+1) break;
		else pos++;
	}
	return pos;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	do{
		if(s1()==s2())
		{
			for(int i=1;i<=n;i++)
			{
				cout<<f[i]<<" ";
			}
			cout<<endl;
		}
	}while(next_permutation(f+1,f+1+n));
//	if(n==1) cout<<1<<endl;
//	else if(n==2) cout<<-1<<endl;
//	else
//	{
//		int l=1,r=n,cnt=n;
//		while(1)
//		{
//			if(cnt) f[l++]=cnt--; else break;
//			if(cnt) f[r--]=cnt--; else break;
//			if(cnt) f[r--]=cnt--; else break;
//			if(cnt) f[l++]=cnt--; else break;
//		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<f[i]<<" ";
//		}
//		cout<<endl;
//	}
}
/*
312  1
312  1
4123 2
4123 2
52134 2
52134 2
632145 3
632145 3
7431256 3
7431256 3
*/
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}