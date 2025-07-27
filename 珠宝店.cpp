#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum,t;
string u;
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
		cin>>u;
		sum=0;
		for(int i=0;i<u.size();i++)
		sum+=u[i]-'A'+1;
		cout<<sum<<endl;
	}
	return 0;
}