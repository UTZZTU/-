#include <bits/stdc++.h>
using namespace std;
string u;
int n;
int main ()
{
	cin>>n;
	getchar();
	while(n--)
	{
		cin>>u;
		cout<<(u[0]-'0'+u[2]-'0')<<endl;
	}
	return 0;
}