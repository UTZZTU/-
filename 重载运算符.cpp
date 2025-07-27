#include <iostream>
using namespace std;
class time24
{
	public:
		time24(int h=0,int m=0,int s=0);
		void set_time(int h,int m,int s);
		void get_time(int &h,int &m,int &s)const;
		time24 operator+(const time24 &t) const;
	private:
		int hours;
		int minutes;
		int seconds;
};
time24::time24(int h,int m,int s):
	hours(h),minutes(m),seconds(s)
	{}
	void time24::set_time(int h,int m,int s)
	{
		hours=h;
		minutes=m;
		seconds=s;
	}
	void time24::get_time(int &h,int &m,int &s)const
	{
		h=hours;
		m=minutes;
		s=seconds;
	}
	time24 time24::operator+(const time24 &t)const
	{
		time24 temp;
		int sens=t.hours*3600+t.minutes*60+t.seconds;
		temp.seconds=seconds+sens;
		temp.minutes=minutes+temp.seconds/60;
		temp.seconds%=60;
		temp.hours=hours+temp.minutes/60;
		temp.minutes%=60;
		temp.hours%=24;
		return temp;
	}
	int main ()
	{
		int h,m,s;
		time24 p1(23,30,57);
		time24 p2(1,15,20);
		time24 p3;
		p3=p1+p2;
		p3.get_time(h,m,s);
		printf("%d %d %d",h,m,s);
		return 0;
	}