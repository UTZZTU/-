#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum=0,js=1;
int main ()
{
	ll a,b;
	string n,u;
	cin>>a>>n>>b;
	for(int i=n.size()-1;i>=0;i--)
	{
		if(n[i]>='A'&&n[i]<='Z')
		sum+=(n[i]-'A'+10)*js;
		else if(n[i]>='0'&&n[i]<='9')
		sum+=(n[i]-'0')*js;
		else
		sum+=(n[i]-'a'+10)*js;
		js*=a;
	}
	while(sum!=0)
	{
		int x=sum%b;
		if(x>=0&&x<=9)
		u+=x+'0';
		else
		u+=x%10+'A';
		sum/=b;
	}
	reverse(u.begin(),u.end());
	cout<<u;
	return 0;
}