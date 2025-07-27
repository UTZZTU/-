#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,res,f[1010][1010];
bool check(int x,int y)
{
	int res=1;
	for(int i=1;i<=y;i++)
	{
		res*=x;
		if(res>n) return false;
	}
	return true;
}
//void dfs(int x,int y)
//{
//	if(!f[x][y]&&x<=n&&x>=2&&y>=2&&y<=m)
//	{
////		cout<<x<<" "<<y<<endl;
//		f[x][y]=1;
//		res--;
//	}
//	for(int i=2;i*i<=y;i++)
//	{
//		if(y%i==0)
//		{
//			if(check(x,i))
//			{
//				dfs(pow(x,i),y/i);
//			}
//			if(check(x,y/i))
//			{
//				dfs(pow(x,y/i),i);
//			}
//		}
//	}
//	return;
//}
bool isPrime(int x)
{
	if(x<=1) return false;
	else if(x==2||x==3) return true;
	else if(x%6!=1&&x%6!=5) return false;
	else
	{
		for(int i=5;i<=floor(sqrt(x));i++)
		{
			if(x%i==0||x%(i+2)==0) return false;
		}
		return true;
	}
}
void solve(int x,int y)
{
	int cnt=0;
	for(int i=2;i*i<=y;i++)
	{
		if(y%i==0)
		{
			if(check(x,i))
			{
				int j=pow(x,i);
				if(j>=2&&j<=n&&(y/i)>=2&&(y/i)<=m&&!f[j][y/i])
				{
//					cout<<j<<" "<<y/i<<endl;
					f[j][y/i]++;
					cnt++;
				}
			}
			if(check(x,y/i))
			{
				int j=pow(x,y/i);
				if(j>=2&&j<=n&&i>=2&&i<=m&&!f[j][i])
				{
//					cout<<j<<" "<<i<<endl;
					f[j][i]++;
					cnt++;
				}
			}
		}
	}
	if(y<=m) res-=cnt;
	else
	{
		if(cnt)
		res-=(cnt-1);
	}
//	cout<<res<<endl;
}
int main ()
{
	cin>>n>>m;
	res=(n-1)*(m-1);
//	cout<<res<<endl;
	for(int i=2;i<=n;i++)
	{
			int k=i,maxx=0;
			while(k<=n)
			{
				maxx++;
				k*=i;
			}
			maxx*=m;
//			cout<<maxx<<endl;
			for(int j=4;j<=maxx;j++)
			{
				solve(i,j);
			}
	}
//	for(int i=2;i<=n;i++)
//	{
//		for(int j=2;j<=m;j++)
//		{
//			cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<res;
	return 0;
}

/*
2^6
2 2 2 2 2 2
4 * 3
8*8

8^4
8*8*8*8
2*4*2*4*2*4*2*4 = 4^6
*/
