#include <iostream>
using namespace std;
int a[13];
int main ()
{
	int n,k;
	cin>>n;
	while(n--)
	{
		cin>>k;
		a[k]++;
	}
	for(int i=1;i<12;i++)
    printf("%d ",a[i]);
    printf("%d",a[12]);
    return 0;
}