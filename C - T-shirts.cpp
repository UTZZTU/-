#include <bits/stdc++.h>
using namespace std;
int n,m,maxx,temp1,temp2;
string s;
int main ()
{
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			if(temp2)
			{
				if(temp1>m)
				{
					maxx=max(maxx,temp1+temp2-m);
				}
				else
				{
					maxx=max(maxx,temp2);
				}
			}
			else
			{
				if(temp1>m)
				{
					maxx=max(maxx,temp1-m);
				}
			}
			temp1=temp2=0;
		}
		else if(s[i]=='1')
		{
			temp1++;
		}
		else
		{
			temp2++;
		}
	}
	if(temp2)
	{
		if(temp1>m)
		{
			maxx=max(maxx,temp1+temp2-m);
		}
		else
		{
			maxx=max(maxx,temp2);
		}
	}
	else
	{
		if(temp1>m)
		{
			maxx=max(maxx,temp1-m);
		}
	}
	cout<<maxx<<endl;
	return 0;
}