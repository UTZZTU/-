#include <bits/stdc++.h>
using namespace std;
int a[16],t,pd;
string u;
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>u;
		pd=0;
		memset(a,0,sizeof(a));
		for(int i=0;i<u.size();i++)
		{
			if(u[i]>='0'&&u[i]<='9')
			a[u[i]-'0']++;
			else
			{
				if(u[i]=='A')
				a[1]++;
				else if(u[i]=='T')
				a[10]++;
				else if(u[i]=='X')
				a[14]++;
				else if(u[i]=='D')
				a[15]++;
				else if(u[i]=='J')
				a[11]++;
				else if(u[i]=='Q')
				a[12]++;
				else
				a[13]++;
			}
		}
		for(int i=1;i<=13;i++)
		{
			if(a[i]>=4)
			{
				pd=1;
				break;
			}
		}
		if(pd||a[14]>=1&&a[15]>=1)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
	return 0;
}