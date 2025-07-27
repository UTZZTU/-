#include <bits/stdc++.h>
using namespace std;
int t,n,k,res;
string s;
int main ()
{
	cin>>t;
	while(t--)
	{
		res=0;
		cin>>n>>k;
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='B')
			{
				res++;
			}
		}
		if(res==k)
		{
			puts("0");
		}
		else if(res>k)
		{
			res=0;
			for(int i=s.size()-1;i>=0;i--)
			{
				if(s[i]=='B')
				{
					res++;
					if(res==k+1)
					{
						puts("1");
						printf("%d A\n",i+1);
						break;
					}
				}
			}
		}
		else
		{
			res=0;
			for(int i=s.size()-1;i>=0;i--)
			{
				if(s[i]=='B')
				{
					res++;
					if(res+i==k)
					{
						puts("1");
						printf("%d B\n",i+1);
						break;
					}
				}
				else
				{
					if(res+i+1==k)
					{
						puts("1");
						printf("%d B\n",i+1);
						break;
					}
				}
			}
		}
	}
	return 0;
}