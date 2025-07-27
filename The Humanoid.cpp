#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,h,f[200010],sum,res1,res2;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		sum=0;
		res1=2,res2=1;
		scanf("%lld%lld",&n,&h);
		for(int i=1;i<=n;i++)
		scanf("%lld",&f[i]);
		sort(f+1,f+1+n);
		for(int i=1;i<=n;i++)
		{
			if(f[i]<h)
			{
				h+=f[i]/2;
				sum++;
			}
			else
			{
				if(h*2>f[i])
				{
					if(res1)
					{
						res1--;
						h*=2;
						h+=f[i]/2;
						sum++;
					}
					else if(res2)
					{
						res2--;
						h*=3;
						h+=f[i]/2;
						sum++;
					}
					else
					break;
				}
				else if(h*3>f[i])
				{
					if(res2)
					{
						res2--;
						h*=3;
						h+=f[i]/2;
						sum++;
					}
					else if(res1==2)
					{
						res1=0;
						h*=4;
						h+=f[i]/2;
						sum++;
					}
					else
					break;
				}
				else if(h*4>f[i])
				{
					if(res1==2)
					{
						res1=0;
						h*=4;
						h+=f[i]/2;
						sum++;
					}
					else if(res1&&res2)
					{
						res1--,res2--;
						h*=6;
						h+=f[i]/2;
						sum++;
					}
					else
					break;
				}
				else if(h*6>f[i])
				{
					if(res1&&res2)
					{
						res1--,res2--;
						h*=6;
						h+=f[i]/2;
						sum++;
					}
					else
					break;
				}
				else if(h*12>f[i])
				{
					if(res1==2&&res2)
					{
						res1=0,res2--;
						h*=12;
						h+=f[i]/2;
						sum++;
					}
					else
					break;
				}
				else break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}