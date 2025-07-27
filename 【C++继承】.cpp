#include <iostream>
#include <string>
using namespace std;
class person
{
	public:
		void input(string a,int b,int c);
		void output();
	private:
		string name;
		int year;
		int money;
};
class salesPerson
{
	public:
		void input(string a,int b,int c,int d,int e);
		void output();
	private:
		string name;
		int year;
		int money;
		int xse;
		int lv;
};
void person::input(string a,int b,int c)
{
	name=a;
	year=b;
	money=c;
}
void person::output()
{
	cout<<name<<" "<<year<<" "<<money<<endl;
}
void salesPerson::input(string a,int b,int c,int d,int e)
{
	name=a;
	year=b;
	money=c;
	xse=d;
	lv=e;
}
void salesPerson::output()
{
	cout<<name<<" "<<year<<" "<<money<<" "<<xse<<" "<<lv<<endl;
}
int main ()
{
	person u1;
	salesPerson u2;
	string a;
	int b,c,d,e;
	cin>>a>>b>>c;
	u1.input(a,b,c);
	cin>>a>>b>>c>>d>>e;
	u2.input(a,b,c,d,e);
	u1.output();
	u2.output();
	return 0;
}