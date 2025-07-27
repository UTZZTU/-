#include <bits/stdc++.h>
using namespace std;
int n,k,l[200010],r[200010],f[200010],cs[200010],q,x;
string s;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		l[i]=r[i]=f[i]=cs[i]=0;
	}
	cin>>s;
	s=' '+s;
	string v;
	for(int i=1;i<=k;i++) cin>>l[i];
	for(int i=1;i<=k;i++) cin>>r[i];
	for(int i=1;i<=k;i++)
	{
		f[l[i]]+=i;
		f[r[i]+1]-=i;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]+=f[i-1];
	}
	cin>>q;
	while(q--)
	{
		cin>>x;
		cs[x]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			v+=s[i];
			continue;
		}
		int ll=i,rr=i+1;
		while(rr<=n&&f[rr]==f[ll]) rr++;
		rr--;
		if((rr-ll)&1)
		{
			int lr=rr+ll>>1,rl=rr+ll+1>>1;
			for(int j=ll+1;j<=lr;j++) cs[j]+=cs[j-1];
			for(int j=rr-1;j>=rl;j--) cs[j]+=cs[j+1];
			for(int j=ll;j<=lr;j++)
			{
				if((cs[j]+cs[rr+ll-j])&1)
				{
					v+=s[rr+ll-j];
				}
				else
				{
					v+=s[j];
				}
			}
			for(int j=rl;j<=rr;j++)
			{
				if((cs[j]+cs[rr+ll-j])&1)
				{
					v+=s[rr+ll-j];
				}
				else
				{
					v+=s[j];
				}
			}
		}
		else
		{
			int mid=rr+ll>>1;
			for(int j=ll+1;j<=mid;j++) cs[j]+=cs[j-1];
			for(int j=rr-1;j>=mid;j--) cs[j]+=cs[j+1];
			for(int j=ll;j<=mid;j++)
			{
				if((cs[j]+cs[rr+ll-j])&1)
				{
					v+=s[rr+ll-j];
				}
				else
				{
					v+=s[j];
				}
			}
			for(int j=mid+1;j<=rr;j++)
			{
				if((cs[j]+cs[rr+ll-j])&1)
				{
					v+=s[rr+ll-j];
				}
				else
				{
					v+=s[j];
				}
			}
		}
		i=rr;
	}
	cout<<v<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}