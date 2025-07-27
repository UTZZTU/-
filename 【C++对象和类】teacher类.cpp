#include <iostream>
using namespace std;
class teacher
{
	public:
		teacher(string a,string b);
		teacher(string a,string b,double c,double d,double e);
		void open(double c,double d,double e);
		void display();
	private:
		string num,name;
		double num1,num2,num3,sum1,sum2;
};
teacher::teacher(string a,string b)
{
	num=a;
	name=b;
}
void teacher::open(double c,double d,double e)
{
	num1=c;
	num2=d;
	num3=e;
	sum1=c+d;
	sum2=sum1-e;
}
void teacher::display()
{
	cout<<num<<" "<<name<<" "<<num1<<" "<<num2<<" "<<num3<<" "<<sum1<<" "<<sum2<<endl;
}
teacher::teacher(string a,string b,double c,double d,double e)
{
	num=a;
	name=b;
	num1=c;
	num2=d;
	num3=e;
	sum1=c+d;
	sum2=sum1-e;
}
int main ()
{
	teacher t1("111", "Mary"),t2("222","Alex",4256.78,1234.56, 895.17) ;
	double x,y,z;
	cin>>x>>y>>z;
	t1.open(x,y,z);
	t1.display();
	t2.display();
	return 0;
}