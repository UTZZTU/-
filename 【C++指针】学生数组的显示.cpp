#include <iostream>
#include <string>
using namespace std;
class student
{
	public:
		void intput(string a,string b,int c);
		void display();
	private:
		string num;
		string name;
		int score;
};
void student::intput(string a,string b,int c)
{
	num=a;
	name=b;
	score=c;
}
void student::display()
{
	cout<<num<<" "<<name<<" "<<score<<endl;
}
int main ()
{
	int n;
	cin>>n;
	string n1,n2;
	int n3;
	class student *p=new student[n];
	for(int i=0;i<n;i++)
	{
		cin>>n1>>n2>>n3;
		(p+i)->intput(n1,n2,n3);
	}
	for(int i=0;i<n;i++)
	{
		(p+i)->display();
	}
	return 0;
}