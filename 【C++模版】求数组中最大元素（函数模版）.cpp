#include <iostream>
#include<algorithm>
using namespace std;
template <typename T>
T largest_element(T a[],int g)
{
	sort(a,a+g);
	return a[g-1];
}
int main ()
{
	int n;
	int f1[20],u1;
	char f2[20],u2;
	double f3[20],u3;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>f1[i];
	u1=largest_element(f1,n);
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>f3[i];
	u3=largest_element(f3,n);
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>f2[i];
	u2=largest_element(f2,n);
	cout<<u1<<endl;
	cout<<u3<<endl;
	cout<<u2<<endl;
	return 0;
}