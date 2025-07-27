#include <bits/stdc++.h>
using namespace std;
int n;
string u,v;
int main ()
{
	cin>>n;
	getchar();
	while(n--)
	{
		cin>>u;
		v=u.substr(u.size()-2,u.size());
		if(v=="po")
		{
			cout<<"FILIPINO"<<endl;
		continue;
		}
		v=u.substr(u.size()-4,u.size());
		if(v=="desu"||v=="masu")
		{
			cout<<"JAPANESE"<<endl;
		continue;
		}
		cout<<"KOREAN"<<endl;
	}
	return 0;
}