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
ll n,res;
int main ()
{
	cin>>n;
	if(n%3!=0) res=(n-1)/3*2;
	else res=n/3-1;
	cout<<res;
	return 0;
}

