#include <bits/stdc++.h>
using namespace std;
int n,m,t;
string s[1010];
int main ()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i+1<n&&j+1<m)
			{
				int res=0;
				if(s[i][j]=='y'||s[i][j+1]=='y'||s[i+1][j]=='y'||s[i+1][j+1]=='y')
				res++;
				if(s[i][j]=='o'||s[i][j+1]=='o'||s[i+1][j]=='o'||s[i+1][j+1]=='o')
				res++;
				if(s[i][j]=='u'||s[i][j+1]=='u'||s[i+1][j]=='u'||s[i+1][j+1]=='u')
				res++;
				if(res>=3)
				t++;
			}
		}
	}
	printf("%d",t);
	return 0;
}