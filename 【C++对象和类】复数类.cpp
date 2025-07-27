#include <iostream>
#include <cmath>
using namespace std;
class complex
{
	public:
		complex();
		complex(double a,double b);
		void input(double a,double b);
		void display();
	private:
		double real,imag,magnitude;
};
void complex::input(double a,double b)
{
	real=a;
	imag=b;
    magnitude=sqrt(a*a+b*b);
}
complex::complex(double a,double b)
{
	real=a;
	imag=b;
    magnitude=sqrt(a*a+b*b);
}
complex::complex()
{
	real=1.0;
	imag=1.0;
	magnitude=1.41;
 }
 void complex::display()
 {
 	printf("%.2f+%.2fi  %.2f\n",real,imag,magnitude);
 }
int main ()
{
	complex val1,val2,val3(1.5,2.8);
	double a,b;
	cin>>a>>b;
	val1.input(a,b);
	val1.display();
	val2.display();
	val3.display();
	return 0;
}