#include <bits/stdc++.h>
using namespace std;
int s[100010],n;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>s[i];
	sort(s+1,s+1+n);
	for(int i=2;i<=n;i++)
	s[i]+=s[i-1];
	if(n&1)
	cout<<1<<" "<<s[n]-2*s[n/2];
	else
	cout<<0<<" "<<s[n]-2*s[n/2];
	return 0;
}