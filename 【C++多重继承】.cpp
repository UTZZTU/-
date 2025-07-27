#include <iostream>
using namespace std;
class worker
{
	public:
		worker(string IDValue,string nameValue);
	protected:
		string workerID,wName;
};
class teacher:public worker
{
	public:
		teacher(string IDValue,string nameValue,string titleValue,string specialValue);
		void display();
	protected:
		string title,speciality;
};
class staff:public worker
{
	public:
		staff(string IDValue, string nameValue, string positionValue);
		void display();
	protected:
		string position;
};
class leader:virtual public teacher,virtual public staff
{
	public:
		leader(string IDValue,string nameValue,string titleValue,string specialValue,string positionValue,int num);
		void display();
	private:
		int workNumber;
};
worker::worker(string IDValue,string nameValue)
{
	workerID=IDValue;
	wName=nameValue;
}
teacher::teacher(string IDValue,string nameValue,string titleValue,string specialValue):worker(IDValue,nameValue)
{
	title=titleValue;
	speciality=specialValue;
}
void teacher::display()
{
	cout<<"I am a teacher, my name is "<<wName<<", title is "<<title<<", speciality is "<<speciality<<"."<<endl;
}
staff::staff(string IDValue, string nameValue, string positionValue):worker(IDValue,nameValue)
{
	position=positionValue;
}
void staff::display()
{
	cout<<"I am a staff, my name is "<<wName<<", position is "<<position<<"."<<endl;
}
leader::leader(string IDValue,string nameValue,string titleValue,string specialValue,string positionValue,int num):teacher(IDValue,nameValue,titleValue,specialValue),staff(IDValue,nameValue,positionValue)
{
	workNumber=num;
}
void leader::display()
{
	cout<<"I am a leader, my name is "<<teacher::wName<<", title is "<<title<<", speciality is "<<speciality<<", my position is "<<position<<" and there are "<<workNumber<<" worker in my department."<<endl;
}
int main ()
{
	teacher t1("001","zhangling","instructor","computer");
 staff s1("002","wangping","office");
 leader l1("003","lisan","professor","computer","headmaster",2000);
 t1.display();
 s1.display();
 l1.display();
 return 0;
}