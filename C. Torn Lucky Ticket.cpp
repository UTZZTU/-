#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[10][10][50][50],n,res;
string s[200010];
signed main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		int num=0,pre=0,len=s[i].size();
		for(int j=0;j<len;j++)
		{
			num+=(s[i][j]-'0');
		}
		f[len][len][0][num]++;
		for(int j=0;j<len;j++)
		{
			pre+=(s[i][j]-'0');
			f[len][len-j-1][pre][num-pre]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int num=0,len=s[i].size();
		for(int j=0;j<len;j++)
		{
			num+=(s[i][j]-'0');
		}
		if(len==1)
		{
			res+=f[1][1][0][num];
			for(int j=0;j<=9;j++)
			{
				res+=f[3][2][j][j+num];
			}
			for(int j=0;j<=18;j++)
			{
				res+=f[5][3][j][j+num];
			}
		}else if(len==2)
		{
			res+=f[2][2][0][num];
			for(int j=0;j<=9;j++)
			{
				res+=f[4][3][j][j+num];
			}
		}
		else if(len==3)
		{
			res+=f[3][3][0][num];
			int k=num-2*(s[i][2]-'0');
			if(k>=0)
			{
				res+=f[1][1][0][k];
			}
			for(int j=0;j<=9;j++)
			{
				res+=f[5][4][j][j+num];
			}
		}else if(len==4)
		{
			res+=f[4][4][0][num];
			int k=num-2*(s[i][3]-'0');
			if(k>=0)
			{
				res+=f[2][2][0][k];
			}
		}else
		{
			res+=f[5][5][0][num];
			int k=num-2*(s[i][3]-'0'+s[i][4]-'0');
			if(k>=0)
			{
				res+=f[1][1][0][k];
			}
			k=num-2*(s[i][4]-'0');
			if(k>=0)
			{
				res+=f[3][3][0][k];
			}
		}
	}
	cout<<res;
	return 0;
}