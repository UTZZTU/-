#include<bits/stdc++.h>
using namespace std;
int a[10010];
int n,t;
bool judge(int a[])
{
	a[2] /=__gcd(a[2],a[1]);
	for(int i = 3;i<=n;i++)
	a[2]/=(__gcd(a[2],a[i]));
	if(a[2] == 1)
	return true;
	return false;
}
int main()
{
    cin>>t;
    while(t--)
    {
    	cin>>n;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	if(judge(a))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	}
	return 0;
}


