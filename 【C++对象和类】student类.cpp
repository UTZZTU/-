#include <iostream>
using namespace std;
class student
{
	public:
		student(string a,string b);
		student(string a,string b,int c,int d,int e);
		void open(int c,int d,int e);
		void display();
	private:
		string num,name;
		int num1,num2,num3,sum;
};
student::student(string a,string b)
{
	num=a;
	name=b;
}
void student::open(int c,int d,int e)
{
	num1=c;
	num2=d;
	num3=e;
	sum=c+d+e;
}
void student::display()
{
	cout<<num<<" "<<name<<" "<<num1<<" "<<num2<<" "<<num3<<" "<<sum<<endl;
}
student::student(string a,string b,int c,int d,int e)
{
	num=a;
	name=b;
	num1=c;
	num2=d;
	num3=e;
	sum=c+d+e;
}
int main ()
{
	student st1("111", "John"),st2("222","Mike",67,89,92);
	int x,y,z;
	cin>>x>>y>>z;
	st1.open(x,y,z);
	st1.display();
	st2.display();
	return 0;
}