#include <iostream>
using namespace std;
class Worker
{
	public:
		virtual void printInfo()=0;
		Worker(string a,string b);
	protected:
		string name,place;
};
Worker::Worker(string a,string b)
{
	name=a;
	place=b;
}
class AWorker:public Worker
{
	public:
		AWorker(string a,string b,int c);
		virtual void printInfo();
	private:
		int money;
};
AWorker::AWorker(string a,string b,int c):Worker(a,b)
{
	money=c;
}
void AWorker::printInfo()
{
	cout<<"name: "<<name<<", address: "<<place<<", salary: "<<money<<endl;
}
class BWorker:public Worker
{
	public:
		BWorker(string a,string b,int c,int d);
		virtual void printInfo();
	private:
		int num,sx;
};
BWorker::BWorker(string a,string b,int c,int d):Worker(a,b)
{
	num=c;
	sx=d;
}
void BWorker::printInfo()
{
	cout<<"name: "<<name<<", address: "<<place<<", salary: "<<num*sx<<endl;
}
class CWorker:public Worker
{
	public:
		CWorker(string a,string b,int c,int d);
		virtual void printInfo();
	private:
		int num,sx;
};
CWorker::CWorker(string a,string b,int c,int d):Worker(a,b)
{
	num=c;
	sx=d;
}
void CWorker::printInfo()
{
	cout<<"name: "<<name<<", address: "<<place<<", salary: "<<num*sx<<endl;
}
int main ()
{
	Worker* w = NULL; //基类指针
 //基类指针指向固定工人
 //zhang为姓名,A address是地址,2000是固定工资
    w = new AWorker("zhang", "A address", 2000);
 w->printInfo();
 delete w;
    //基类指针指向计件工人
 //wang为姓名,B address是地址,100是数量,也就是件数,15是单件的薪酬,工资为100*15=1500
 w = new BWorker("wang", "B address", 100, 15);
 w->printInfo();
 delete w;
    //基类指针指向计时工人
 //li为姓名,C address是地址,80是一月工作的小时数,30是一小时的薪酬,工资为80*30=2400
 w = new CWorker("li", "C address", 80, 30);
 w->printInfo();
 delete w;
 return 0;
}