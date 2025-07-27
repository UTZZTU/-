#include <bits/stdc++.h>
using namespace std;
int c,f[2505000],chazhi;
int  judge(int n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(i*i+j*j==n*n)
			return true;
		}
	}
	return false;
}
bool check(int x)
{
	chazhi=-1;
	for(int i=x+1;i<=c/2;i++)
	{
		if(!(c-i-x)&&(c-i-x)%2==0)
		{
			int u=(c-i-x)/2,v=u+x,w=i;
			if(u+v>w&&u+w>v&&w+v>u)
			{
				if(u*u+v*v==w*w||u*u+w*w==v*v||w*w+v*v==u*u||judge(u)+judge(v)+judge(w)>=2)
				{
					return true;
				}
			}
		}
	}
	return false;
}
int main ()
{
	cin>>c;
	int l=0,r=c;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			r=mid;
		}
		else
		l=mid+1;
	}
	cout<<l;
	return 0;
}