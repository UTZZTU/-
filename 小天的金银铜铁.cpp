#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e,A,B,C,D,E;
int main ()
{
	cin>>a>>b>>c>>d>>e;
	cin>>A>>B>>C>>D;
	cout<<((A*a+B*b+C*c-D*d>e)?"YES":"NO")<<endl;
	return 0;
}