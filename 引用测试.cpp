#include<iostream>
using namespace std;
void swap(float& v1,float& v2)
{
	double temp;
	temp=v1;
	v1=v2;
	v2=temp;
}
int main ()
{
	float num1,num2;
	cin>>num1>>num2;
	swap(num1,num2);
	cout<<num1<<" "<<num2;
	return 0;
}