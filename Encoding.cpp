#include<iostream>
using namespace std;
int main ()
{
	int n,i,j,sum;
	char s[10010],c;
	cin>>n;
	getchar();
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=0;s[j]!='\0';j++)
		{
			sum=1;
			while(s[j]==s[j+1]&&s[j+1]!='\0')
			{
				j++;
				sum++;
			}
			if(sum!=1)
			printf("%d",sum);
			printf("%c",s[j]);
		}
			printf("\n");
	}
	return 0;
}