#include <bits/stdc++.h>
using namespace std;
int t,n,k,res;
string s;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		res=0;
		getchar();
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='B')
			{
				res++;
				i+=k-1;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}