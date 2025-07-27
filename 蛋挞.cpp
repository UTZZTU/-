#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
int main ()
{
	cin>>a>>b;
	if(a/b==a%b)
	cout<<"same";
	else if(a/b>a%b)
	cout<<"niuniu eats less than others";
	else
	cout<<"niuniu eats more than others";
	return 0;
}