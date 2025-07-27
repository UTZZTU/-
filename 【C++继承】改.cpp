#include <bits/stdc++.h>
using namespace std;
class person
{
	public:
		 person(string a,char b,string c)
		{
			name=a;
			xb=b;
			ID=c;
		}
		void Display()
		{
			cout<<"The name is "<<name<<". The sex is "<<xb<<". The pID is "<<ID<<"."<<endl;
		}
	protected:
		string name;
		char xb;
		string ID;
};
class student:public person
{
	public:
		student(string a,char b,string c,string d,string e):person(a,b,c)
		{
			xh=d;
			zy=e;
		}
		void display()
		{
			cout<<"The name is "<<name<<". The sex is "<<xb<<". The pID is "<<ID<<"."<<" The stuID is"<<xh<<". The major is "<<zy<<"."<<endl;
		}
		private:
			string xh;
			string zy;
};
int main ()
{
	string a,b,c,d;
	char e;
	cin>>a>>e>>b;
	person s1(a,e,b);
	cin>>a>>e>>b>>c>>d;
	student s2(a,e,b,c,d);
	s1.Display();
	s2.display();
	return 0;
}