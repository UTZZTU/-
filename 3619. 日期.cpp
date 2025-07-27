#include <bits/stdc++.h>
using namespace std;
string a[7]={"Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednesday"};
int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int sum;
int main ()
{
	int m,d;
	cin>>m>>d;
	for(int i=4;i<m;i++)
	{
		sum+=b[i];
	}
	sum+=d;
	sum-=12;
	sum%=7;
	cout<<a[sum];
	return 0;
}