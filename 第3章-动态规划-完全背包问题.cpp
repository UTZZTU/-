#include <bits/stdc++.h>
using namespace std;
int n,w[1010],v[1010],b,f[1010][1010],ii[1010][1010],tt[1010];
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];
	}
	cin>>b;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(j-w[i]>=0)
			{
				f[i][j]=max(f[i-1][j],f[i][j-w[i]]+v[i]);
			}
			else
			f[i][j]=f[i-1][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(j-w[i]>=0)
			{
				if(f[i-1][j]>=f[i][j-w[i]]+v[i])
			{
				ii[i][j]=ii[i-1][j];
			}
			else
			{
				ii[i][j]=i;
			}
			}
			else
			{
				ii[i][j]=ii[i-1][j];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<"F[ "<<i<<" ]: ";
		for(int j=1;j<=b;j++)
		{
			cout<< setw(5) << f[i][j];
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<"i[ "<<i<<" ]: ";
		for(int j=1;j<=b;j++)
		{
			cout << setw(5) << ii[i][j];
		}
		cout<<endl;
	}
	int pos=b;
	while(1)
	{
		tt[ii[n][pos]]+=1;
		pos-=w[ii[n][pos]];
		if(pos<=0||ii[n][pos]==0)
		break;
	}
	cout<<"[";
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		cout<<" ";
		cout<<tt[i];
		if(i!=n)
		cout<<",";
	}
	cout<<"]";
	return 0;
}