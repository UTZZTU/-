#include <bits/stdc++.h>
using namespace std;
int s[10];
string u;
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	s[u[i]-'0']++;
	for(int i=0;i<10;i++)
	{
		if(s[i])
		printf("%d:%d\n",i,s[i]);
	}
	return 0;
}