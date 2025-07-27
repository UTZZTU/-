#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll derta,x1,x2,a0,a1,p,q,m,k,arf,beta;
string n;
int main ()
{
	cin>>a0>>a1>>p>>q;
	derta=sqrt(p*p+4q);
	x1=(p+derta)/2;
	x2=(p-derta)/2;
	beta=(x1*a0-a1)/(x1-x2);
	arf=a0-beta;
	cin>>m>>k;
	getchar();
	cin>>n;
	
}