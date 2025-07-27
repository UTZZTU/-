#include <iostream>
using namespace std;
int main ()
{
	int n,sum=0,i,pd=0,k=0;
	char a,b,s[200010];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		s[k]=a;
		k++;
		i++;
		if(i>n)
		break;
		cin>>b;
		while(b==a&&i<=n)
		{
			sum++;
			i++;
			cin>>b;
		}
		if(b!=a)
		{
			s[k]=b;
			k++;
		}
	}
	if((n-sum)%2==0)
	{
		printf("%d\n",sum);
		for(i=0;i<k;i++)
		cout<<s[i];
	}
	else
	{
		printf("%d\n",sum+1);
		if(sum+1==n)
		printf("\n");
		else
		{
			for(i=0;i<k-1;i++)
			cout<<s[i];
		}
	}
	return 0;
}
