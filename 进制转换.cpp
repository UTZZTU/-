#include <stdio.h>
typedef long long ll;
int main ()
{
	ll n,k,i=0;
	char s[1000];
	scanf("%lld %lld",&n,&k);
	while(n!=0)
	{
		if(n%k>=0&&n%k<=9)
		s[i]=n%k+'0';
		else
		s[i]=n%k-10+'A';
		i++;
		n/=k;
	}
	i--;
	for(i;i>=0;--i)
	printf("%c",s[i]);
	return 0;
}