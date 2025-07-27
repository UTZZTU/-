#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res;
string u;
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		res=res*10+(u[i]-'0');
	}
	if(res%62==0||u.find("62")!=-1)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}