#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int d,h,m;
	cin>>d>>h>>m;
	if(d<11||d==11&&h<11||d==11&&h==11&&m<11)
	cout<<-1;
	else
	{
		int f=(d-11)*24*60+(h-11)*60+(m-11);
		cout<<f;
	}
	return 0;
}