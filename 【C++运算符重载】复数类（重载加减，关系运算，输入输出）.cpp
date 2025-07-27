#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
class complex
{
	public:
		complex();
		void setReal(double realVal);
		void setImag(double imagVal);
		void getReal(double &a);
		void getImag(double &b);
		complex operator+(const complex &t) const;
		complex operator-(const complex &t) const;
		bool operator==(const complex &t) const;
		bool operator!=(const complex &t) const;
		bool operator>(const complex &t) const;
		bool operator<(const complex &t) const;
	private:
	double real;            
   double imaginary;	
};
complex::complex()
{
	real=0;
	imaginary=0;
}
void complex::setReal(double realVal)
{
	real=realVal;
}
void complex::setImag(double imagVal)
{
	imaginary=imagVal;
}
void complex::getReal(double &a)
{
	a=real;
}
void complex::getImag(double &b)
{
	b=imaginary;
}
complex complex::operator+(const complex &t) const
{
	complex u;
	u.real=real+t.real;
	u.imaginary=imaginary+t.imaginary;
	return u;
}
complex complex::operator-(const complex &t) const
{
	complex u;
	u.real=real-t.real;
	u.imaginary=imaginary-t.imaginary;
	return u;
}
bool complex::operator==(const complex &t) const
{
	if(real==t.real&&imaginary==t.imaginary)
	return true;
	else
	return false;
}
bool complex::operator!=(const complex &t) const
{
	if(real!=t.real||imaginary!=t.imaginary)
	return true;
	else
	return false;

}
bool complex::operator>(const complex &t) const
{
	double s1=sqrt(real*real+imaginary*imaginary);
	double s2=sqrt(t.real*t.real+t.imaginary*t.imaginary);
	if(s1>s2)
	return true;
	else
	return false;

}
bool complex::operator<(const complex &t) const
{
	double s1=sqrt(real*real+imaginary*imaginary);
	double s2=sqrt(t.real*t.real+t.imaginary*t.imaginary);
	if(s1<s2)
	return true;
	else
	return false;
}
istream& operator>>(istream &is,complex &t)
{
	double real,imag;
    char c1,c2;
    is>>real>>c1>>imag>>c2;
    if(c1=='-')
    imag*=-1;
    t.setReal(real);
    t.setImag(imag);
    return is;
}
ostream& operator<<(ostream &os,complex &t)
{
	double real,imag;
	t.getReal(real);
	t.getImag(imag);
	if(real==0&&imag==0)
	{
		os<<0<<endl;
	}
	else
	{
		if(real!=0)
		os<<fixed<<setprecision(2)<<real;
		if(imag>0)
		{
			os<<"+"<<fixed<<setprecision(2)<<imag<<"i"<<endl;
		}
		else if(imag<0)
		{
			os<<fixed<<setprecision(2)<<imag<<"i"<<endl;
		}
	}
	return os;
}
int main ()
{
complex c1,c2,c3,c4,c5;
cin>>c1>>c2;
c3=c1+c2;
c4=c1-c2;
if(c3!=c4)
{
if(c3<c4)
{
cout<<"c3 is less than c4";
c5=c4-c3;
}
if(c3>c4)
{
cout<<"c3 is greater than c4";
c5=c3-c4;
}
}
if(c3==c4)
{
cout<<"c3 and c4 are equal";
c5=c4 ;
}
cout<<endl;
cout<<c5 ;
return 0;
}