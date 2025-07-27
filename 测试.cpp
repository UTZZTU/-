#include <iostream>
using namespace std;
int main ()
{
	int n,sum=0,i,pd=0;
	char a,b;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		i++;
		if(i>n)
		break;
		cin>>b;
		while(b==a)
		{
			sum++;
			i++;
			cin>>b;
			if(i>n)
			break;
		}
		if(i>n)
		break;
	}
	if((n-sum)%2==0)
	printf("%d",sum);
	else
	printf("%d",sum+1);
	return 0;
}