#include <bits/stdc++.h>
using namespace std;
int f[30],t,n,res;
int main ()
{
	cin>>t;
	while(t--)
	{
		memset(f,0,sizeof f);
		cin>>n;
		string s;
		cin>>s;
		for(int i=0;i<n;i++)
		{
			f[s[i]-'A'+1]++;
		}
		res=0;
		for(int i=1;i<=26;i++)
		{
			if(f[i]>=i) res++;
		}
		cout<<res<<endl;
	}
	return 0;
}