#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int a=1,b=2,*p=&a,*q=&b,tmp;
	tmp=*p;
	*p=*q;
	*q=tmp;
	cout<<a<<" "<<b;
	return 0;
}