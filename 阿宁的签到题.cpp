#include <bits/stdc++.h>
using namespace std;
int x;
int main ()
{
	cin>>x;
	if(x>1919810)
	cout<<"can not imagine";
	else if(x>114514)
	cout<<"very hard";
	else if(x>10032)
	cout<<"hard";
	else if(x>233)
	cout<<"medium";
	else if(x>7)
	cout<<"easy";
	else
	cout<<"very easy";
	return 0;
}