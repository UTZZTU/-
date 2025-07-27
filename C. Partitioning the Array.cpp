#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int n,a[200010];
bool judge(int x)
{
	int cnt=n/x;
	int gcds=0;
	for(int i=1;i<=x;i++)
	{
//		set<int> st;
		int pre=-1;
		for(int j=0;j<cnt;j++)
		{
//			st.insert(a[j*x+i]);
			if(pre==-1) pre=a[j*x+i];
			else
			{
				gcds=gcd(gcds,abs(a[j*x+i]-pre));
//				pre=a[j*x+i];
				if(gcds==1) return false;
			}
		}
//		int pre=-1;
//		for(auto it=st.begin();it!=st.end();it++)
//		{
//			if(pre==-1) pre=*it;
//			else
//			{
//				gcds=gcd(gcds,*it-pre);
//				pre=*it;
//				if(gcds==1) return false;
//			}
//		}
	}
//	cout<<"yes:"<<x<<endl;
	return true;
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int res=0;
	for(int i=1;i<=(int)(sqrt(n));i++)
	{
		if(n%i==0)
		{
			int l=i,r=n/i;
			if(judge(l)) res++;
			if(r!=l&&judge(r)) res++;
		}
	}
	printf("%d\n",res);
}
int main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t=1;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}
