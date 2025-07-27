#include <bits/stdc++.h>
using namespace std;
int a[10];
int main ()
{
	string u;
	getline(cin,u);
	for(int i=0;i<u.size();i++)
	{
		a[u[i]-'0']++;
	}
	for(int i=0;i<10;i++)
	{
		if(!a[i])
		continue;
		cout<<i<<":"<<a[i]<<endl;
	}
	return 0;
}