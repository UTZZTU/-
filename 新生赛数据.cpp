#include <bits/stdc++.h>
using namespace std;
#define random(x) rand()%(x)
int t=1e5-5;
int main ()
{
	cout<<100000<<endl;
	for(int i=1;i<=t;i++)
	{
		cout<<random(1000000000)+1<<" "<<random(1000000000)+1<<" "<<random(1000000000)+1<<endl;
	}
	cout<<1<<" "<<1<<" "<<1<<endl;
	cout<<1<<" "<<1000000000<<" "<<1000000000<<endl;
	cout<<1000000000<<" "<<1<<" "<<1<<endl;
	cout<<999999998<<" "<<1000000000<<" "<<999999999<<endl;
	cout<<1000000000<<" "<<1000000000<<" "<<1000000000<<endl;
	return 0;
}