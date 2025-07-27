#include <bits/stdc++.h>
using namespace std;
int minn=0x3f3f3f3f;
int main ()
{
	int a,b,x,y;
	cin>>a>>b>>x>>y;
	minn=min(abs(b-a),min(abs(y-a)+abs(b-x),abs(x-a)+abs(b-y)));
	cout<<minn;
	return 0;
}