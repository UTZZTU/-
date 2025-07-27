#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int a[9],ans=0;
	for(int i=1;i<=9;i++)
	a[i-1]=i;
	do
	{
		if(a[0]*100+a[1]*10+a[2]+a[3]*100+a[4]*10+a[5]==a[6]*100+a[7]*10+a[8])
		ans++;
	}while(next_permutation(a,a+9));
	cout<<ans;
	return 0;
}