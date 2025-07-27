#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI pair<int,int> 
#define fi first
#define se second
#define pb push_back
#define fr front
#define bk back
#define gl getline
int n,k,l,r;
int main ()
{
	cin>>n>>k;
	if(k*3<=n)
	{
		for(int i=1;i<=n-3*k;i++) cout<<"y";
		for(int i=1;i<=k;i++) cout<<"you";
	}
	else cout<<"-1";
	return 0;
}