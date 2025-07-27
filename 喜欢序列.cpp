#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],l,r,w,cf[200010],sum,bh[200010],cnt,h[200010],hh[200010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cf[i]=a[i]-a[i-1];
	}
	cnt++;
	bh[1]=cnt;
	bh[n+1]=0;
	cf[n+1]=10000000000;
	for(int i=2;i<=n;i++)
	{
		if(cf[i]==1)
		{
			bh[i]=bh[i-1];
		}
		else
		{
			bh[i]=++cnt;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int j=i;
		int num=0;
		while(j<=n&&bh[j]==bh[i])
		{
			num++;
			j++;
		}
		j--;
		hh[bh[i]]=num;
		sum+=num*num;
		for(int k=i;k<=j;k++)
		{
			h[k]=num;
			num--;
		}
		i=j;
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<h[i]<<endl;
//	}
	while(m--)
	{
		cin>>l>>r>>w;
		if(w==0)
		{
			cout<<sum<<endl;
		}
		else
		{
			if(bh[l]==bh[r])
			{
				if(bh[l]==bh[l-1]&&bh[r]==bh[r+1])
				{
					int len=hh[bh[l]];
					cout<<sum-len*len+(r-l+1)*(r-l+1)+(h[r]-1)*(h[r]-1)+(len-r+l-h[r])*(len-r+l-h[r])<<endl;
				}
				else if(bh[l]==bh[l-1])
				{
					if(cf[r+1]-w==1)
					{
						int len1=hh[bh[l]],len2=hh[bh[r+1]];
						cout<<sum-len1*len1-len2*len2+(len1-h[l])*(len1-h[l])+(h[l]+len2)*(h[l]+len2)<<endl;
					}
					else
					{
						int len=hh[bh[l]];
						cout<<sum-len*len+(len-h[l])*(len-h[l])+(r-l+1)*(r-l+1)<<endl;
					}
				}
				else if(bh[r]==bh[r+1])
				{
					if(cf[l]+w==1)
					{
						int len1=hh[bh[l-1]],len2=hh[bh[r]];
						cout<<sum-len1*len1-len2*len2+(h[r]-1)*(h[r]-1)+(r-l+1+len1)*(r-l+1+len1)<<endl;
					}
					else
					{
						int len=hh[bh[l]];
						cout<<sum-len*len+(h[r]-1)*(h[r]-1)+(r-l+1)*(r-l+1)<<endl;
					}
				}
				else
				{
					if(cf[l]+w==1&&cf[r+1]-w==1)
					{
						int len1=hh[bh[l-1]],len2=r-l+1,len3=hh[bh[r+1]];
						cout<<sum-len1*len1-len2*len2-len3*len3+(len1+len2+len3)*(len1+len2+len3)<<endl;
					}
					else if(cf[l]+w==1)
					{
						int len1=hh[bh[l-1]],len2=r-l+1;
						cout<<sum-len1*len1-len2*len2+(len1+len2)*(len1+len2)<<endl;
					}
					else if(cf[r+1]-w==1)
					{
						int len1=hh[bh[r+1]],len2=r-l+1;
						cout<<sum-len1*len1-len2*len2+(len1+len2)*(len1+len2)<<endl;
					}
					else
					{
						cout<<sum<<endl;
					}
				}
			}
			else
			{
				if(bh[l]==bh[l-1]&&bh[r]==bh[r+1])
				{
					int len1=hh[bh[l]],len2=hh[bh[r]];
					cout<<sum-len1*len1-len2*len2+h[l]*h[l]+(len1-h[l])*(len1-h[l])+(h[r]-1)*(h[r]-1)+(len2-h[r]+1)*(len2-h[r]+1)<<endl;
				}
				else if(bh[l]==bh[l-1])
				{
					if(cf[r+1]-w==1)
					{
						int len1=hh[bh[l]],len2=hh[bh[r]],len3=hh[bh[r+1]];
						cout<<sum-len1*len1-len2*len2-len3*len3+h[l]*h[l]+(len1-h[l])*(len1-h[l])+(len3+len2)*(len3+len2)<<endl;
					}
					else
					{
						int len=hh[bh[l]];
						cout<<sum-len*len+(len-h[l])*(len-h[l])+h[l]*h[l]<<endl;
					}
				}
				else if(bh[r]==bh[r+1])
				{
					if(cf[l]+w==1)
					{
						int len1=hh[bh[l]],len2=hh[bh[r]],len3=hh[bh[l-1]];
						cout<<sum-len1*len1-len2*len2-len3*len3+(h[r]-1)*(h[r]-1)+(len2-h[r]-1)*(len2-h[r]-1)+(len1+len3)*(len1+len3)<<endl;
					}
					else
					{
						int len=hh[bh[r]];
						cout<<sum-len*len+(h[r]-1)*(h[r]-1)+(len-h[r]-1)*(len-h[r]-1)<<endl;
					}
				}
				else
				{
					if(cf[l]+w==1&&cf[r+1]-w==1)
					{
						int len1=hh[bh[l-1]],len2=hh[bh[l]],len3=hh[bh[r]],len4=hh[bh[r+1]];
						cout<<sum-len1*len1-len2*len2-len3*len3-len4*len4+(len1+len2)*(len1+len2)+(len3+len4)*(len3+len4)<<endl;
					}
					else if(cf[l]+w==1)
					{
						int len1=hh[bh[l-1]],len2=hh[bh[l]];
						cout<<sum-len1*len1-len2*len2+(len1+len2)*(len1+len2)<<endl;
					}
					else if(cf[r+1]-w==1)
					{
						int len1=hh[bh[r+1]],len2=hh[bh[r]];
						cout<<sum-len1*len1-len2*len2+(len1+len2)*(len1+len2)<<endl;
					}
					else
					{
						cout<<sum<<endl;
					}
				}
			}
		}
	}
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}