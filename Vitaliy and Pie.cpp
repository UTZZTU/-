#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char s1,s2;
	int n,i,a[26],sum=0;
	memset(a,0,sizeof(a));
	cin>>n;
	for(i=1;i<=n-1;i++)
	{
	   cin>>s1>>s2;
	   if(s1-s2!=32)
	   {
	   	a[s1-'a']++;
	   	if(a[s2-'A']>0)
	   	a[s2-'A']--;
	   	else
	   	sum++;
	   }
	}
	printf("%d",sum);
	return 0;
}