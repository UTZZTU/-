#include <bits/stdc++.h>
using namespace std;
int n,flag=-1,res;
string s;
int main ()
{
	cin>>n;
	getchar();
	cin>>s;
	for(int i=0;i<=n-2;i+=2)
	{
		if(s[i]=='H')
		{
			if(s[i+1]=='G')
			{
				if(flag==1) res++;
				flag=0;
			}else
			{
				;
			}
		}
		else
		{
			if(s[i+1]=='G')
			{
				;
			}else
			{
				if(!flag) res++;
				flag=1;
			}
		}
	}
	cout<<res+(flag==1)<<endl;
	return 0;
}