#include <bits/stdc++.h>
using namespace std;
int k;
string a="ChuiZi",b="JianDao",c="Bu",d="End",u;
int main ()
{
	cin>>k;
	getchar();
	for(int i=1;;i++)
	{
		cin>>u;
		if(u==d) break;
		if(i%(k+1)==0) cout<<u<<endl;
		else
		{
			if(u==a) cout<<c<<endl;
			else if(u==b) cout<<a<<endl;
			else cout<<b<<endl;
		}
	}
	return 0;
}