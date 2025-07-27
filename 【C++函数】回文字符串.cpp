#include <iostream>
#include <string>
using namespace std;
bool cmp(string a)
{
	int i,j,l;
	l=a.length();
	i=0;
	j=l-1;
	while((a[i]==a[j]||a[i]-a[j]==32||a[j]-a[i]==32)&&i<j)
	{
		i++;
		j--;
	}
	if(i>=j)
	return true;
	else
	return false;
}
int main ()
{
	string a;
	getline(cin,a);
	if(cmp(a))
	cout<<"true";
	else
	cout<<"false";
	return 0;
}