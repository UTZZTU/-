#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a;
	getline(cin,a);
	int i,sum=0,js=0;
	double s;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z')
		{
			sum++;
			if(i-1<0||a[i-1]==','||a[i-1]=='.'||a[i-1]==' ')
				js++;
		}
	}
	s=sum*1.0/js;
	printf("%.1f",s);
	return 0;
}