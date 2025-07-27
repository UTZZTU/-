#include <iostream>
using namespace std;
class student
{
	public:
		void eat();
		student(string s);
	private:
		string name;
};
class teacher
{
	public:
		void eat();
		teacher(string s);
	private:
		string name;
};
class boss
{
	public:
		void eat();
		boss(string s);
	private:
		string name;
};
void student::eat()
{
	cout<<"I am a student, my name is "<<name<<", I want to have lunch at mess hall!"<<endl;
}
student::student(string s)
{
	name=s;
}
teacher::teacher(string s)
{
	name=s;
}
boss::boss(string s)
{
	name=s;
}
void teacher::eat()
{
	cout<<"I am a teacher, my name is "<<name<<", I want to eat potato in CHUANWEI restaurant!"<<endl;
}
void boss::eat()
{
	cout<<"I am a boss, my name is "<<name<<", I want to eat fish in GAODIJIE restaurant!"<<endl;
}
int main ()
{
	student s("xiao li");
 teacher t("zhang");
 boss b("wang");
 s.eat();
 t.eat();
 b.eat(); 
 return 0;
}