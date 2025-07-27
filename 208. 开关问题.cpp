#include <bits/stdc++.h>
using namespace std;
int t,n,x,y,a[35][35],k;
int guass()
{
	int r,c;
	for(r=1,c=1;c<=n;c++)
	{
		int t=r;
		for(int i=r+1;i<=n;i++)
		{
			if(a[i][c])
			{
				t=i;
				break;
			}
		}
		if(!a[t][c]) continue;
		for(int i=c;i<=n+1;i++) swap(a[t][i],a[r][i]);
		for(int i=r+1;i<=n;i++)
		{
			for(int j=n+1;j>=c;j--)
			{
				a[i][j]^=a[i][c]&a[r][j];
			}
		}
		r++;
	}
	int res=1;
	if(r<n+1)
	{
		for(r;r<=n;r++)
		{
			if(a[r][n+1]) return -1;
			res*=2;
		}
	}
	return res;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			a[i][n+1]^=k;
			a[i][i]=1;
		}
		while(cin>>x>>y)
		{
			if(!x&&!y)
			break;
			a[y][x]=1;
		}
		k=guass();
		if(k==-1) cout<<"Oh,it's impossible~!!"<<endl;
		else cout<<k<<endl;
	}
	return 0;
}