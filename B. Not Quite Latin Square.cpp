#include <bits/stdc++.h>
using namespace std;
int t,a,b,c;
string s[10];
int main ()
{
	cin>>t;
	while(t--)
	{
		a=b=c=0;
		for(int i=0;i<3;i++)
		{
			cin>>s[i];
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(s[i][j]=='A') a++;
				else if(s[i][j]=='B') b++;
				else if(s[i][j]=='C') c++; 
			}
		}
		if(a!=3) cout<<"A"<<endl;
		else if(b!=3) cout<<"B"<<endl;
		else cout<<"C"<<endl;
	}
	return 0;
}