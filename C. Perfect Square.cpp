#include <bits/stdc++.h>
using namespace std;
int t,n,res;
string s[1010];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		res=0;
		getchar();
		for(int i=0;i<n;i++)
		cin>>s[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(s[i][j]!=s[j][n-i-1])
				{
					res+=abs(s[i][j]-s[j][n-i-1]);
					if(s[i][j]<s[j][n-i-1])
					s[i][j]=s[j][n-i-1];
					else
					s[j][n-i-1]=s[i][j];
				}
				
//				cout<<j<<" "<<n-i-1<<endl;
//				cout<<res<<endl;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(s[i][j]!=s[j][n-i-1])
				{
					res+=abs(s[i][j]-s[j][n-i-1]);
					if(s[i][j]<s[j][n-i-1])
					s[i][j]=s[j][n-i-1];
					else
					s[j][n-i-1]=s[i][j];
				}
				
//				cout<<j<<" "<<n-i-1<<endl;
//				cout<<res<<endl;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}

/*
4,1 => 1,1
3,1 => 1,2
2,2 => 2,3
3,3 => 3,2
*/ 