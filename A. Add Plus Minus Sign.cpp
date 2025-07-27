#include <bits/stdc++.h>
using namespace std;
int t,n,res;
string a;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		getchar();
		cin>>a;
		res=a[0]-'0';
		for(int i=1;i<n;i++)
		{
			if(a[i]=='0')
			cout<<"+";
			else
			{
				if(res>=1)
				{
					cout<<"-";
					res--;
				}
				else
				{
					cout<<"+";
					res++;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}