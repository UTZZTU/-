#include <iostream>
#include <algorithm>
using namespace std;
int q[100000],h[100000],a[50010];
long long ans[50010];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,fs=0,i,j,t=0,sum1,sum2,k,pd=0,w,sum;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		ans[i]=a[i]+ans[i-1];
		if(a[i]<=0)
		fs++;
	}
	if(fs==n)
	{
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	else
	{
		i=1;
		while(i<=n)
		{
			sum1=0;
			sum2=0;
			pd=0;
			while(a[i]<=0&&i<=n)
			i++;
			j=i;
			while(pd==0)
			{
				while(a[j]>=0&&j<=n)
			{
				j++;
			}
			k=j;
			while(a[k]<=0&&k<=n)
			{
				sum1+=a[k];
				k++;
			}
			if(k==n)
			{
				pd=1;
				break;
			}
			w=k;
			while(a[w]>=0&&w<=n)
			{
				sum2+=a[w];
				w++;
			}
			if(sum2>=sum1)
			{
				j=w;
			}
			else
			{
              break;
			}
			}
			if(k==n)
		{
			q[t]=i;
			h[t]=j-1;
			break;
		}
		else
		{
			q[t]=i;
			h[t]=j-1;
			t++;
			i=j;
		}
		}
		sum=0;
		for(i=0;i<=t;i++)
		{
			if(h[i]-q[i]>sum)
			sum=h[i]-q[i];
		}
		cout<<sum<<endl;
		return 0;
	}
}