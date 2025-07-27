#include <bits/stdc++.h>
using namespace std;
int a,b,res,ans;
int main ()
{
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		printf("%5d",i);
		res++;
		ans+=i;
		if(res%5==0||i==b)
		printf("\n");
	}
	printf("Sum = %d",ans);
	return 0;
}