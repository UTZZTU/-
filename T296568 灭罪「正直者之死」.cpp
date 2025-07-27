#include <bits/stdc++.h>
using namespace std;
int n,f[510],k,res,flag=1;
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	sort(f+1,f+1+n);
	int pos=lower_bound(f+1,f+1+n,0)-f;
	if(pos>n) pos=n;
	int pos1=pos-1,pos2=pos+1;
	int ans=f[pos];
	res=1;
	while(pos1>=1||pos2<=n)
	{
		if(pos1>=1&&ans+f[pos1]<pow(2,k-1)&&ans+f[pos1]>=-pow(2,k-1)||pos2<=n&&ans+f[pos2]<pow(2,k-1)&&ans+f[pos2]>=-pow(2,k-1))
		;
		else
		break;
		if(flag)
		{
			if(pos2>n)
			{
				flag=0;
				continue;
			}
			else
			{
				if(ans+f[pos2]<pow(2,k-1)&&ans+f[pos2]>=-pow(2,k-1))
				{
					ans+=f[pos2];
					res++;
					pos2++;
				}
				else
				{
					flag=0;
					continue;
				}
			}
		}
		else
		{
			if(pos1<1)
			{
				flag=1;
				continue;
			}
			else
			{
				if(ans+f[pos1]<pow(2,k-1)&&ans+f[pos1]>=-pow(2,k-1))
				{
					ans+=f[pos1];
					res++;
					pos1--;
				}
				else
				{
					flag=1;
					continue;
				}
			}
		}
	}
	cout<<res<<endl;
	return 0;
}