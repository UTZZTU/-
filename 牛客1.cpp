#include <bits/stdc++.h>
using namespace std;
int t;
char s[50];
void judge()
{
	int res1=0,res2=0;
	for(int i=1;i<=10;i++)
	{
		if(i&1)
		{
			if(s[i]=='1')
			res1++;
			if(res1>res2+(10-i)/2+1)
			{
				cout<<i<<endl;
				return;
			}
			if(res2>res1+(10-i)/2)
			{
				cout<<i<<endl;
				return;
			}
		}
		else
		{
			if(s[i]=='1')
			res2++;
			if(res2>res1+(10-i)/2)
			{
				cout<<i<<endl;
				return;
			}
			if(res1>res2+(10-i)/2)
			{
				cout<<i<<endl;
				return;
			}
		}
	}
	if(res1>res2||res1<res2)
	{
		cout<<10<<endl;
	return;
	}
	cout<<-1<<endl;;
	return;
}
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>s+1;
		judge();
	}
	return 0;
}