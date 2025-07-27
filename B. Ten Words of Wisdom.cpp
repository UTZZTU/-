#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,maxx,pos;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		maxx=0,pos=-1;
		for(int i=1;i<=n;i++)
		{
			cin>>a>>b;
			if(a<=10)
			{
				if(pos==-1) pos=i,maxx=b;
				else
				{
					if(b>maxx) maxx=b,pos=i;
				}
			}
		}
		cout<<pos<<endl;
	}
	return 0;
}