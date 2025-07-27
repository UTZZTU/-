#include <bits/stdc++.h>
using namespace std;
int f[1000][100][150];
int k,x;
int qmi(int a,int b,int p)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
void add(int a[],int b[], int c[]){
	int p=0;
	for(int i=0;i<150;i++)
	{
		p+=b[i]+c[i];
		a[i]=p%10;
		p/=10;
	}
}
int main ()
{
	cin>>k>>x;
	int n=qmi(x%1000,x,1000);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i&&j<k;j++)
		{
			if(!j) f[i][j][0]=1;
			else
			add(f[i][j], f[i-1][j], f[i-1][j-1]);
		}
	}
	int *g = f[n-1][k-1];
	int i=149;
	while(!g[i])
	i--;
	for(i;i>=0;i--)
	{
		cout<<g[i];
	}
	return 0;
}