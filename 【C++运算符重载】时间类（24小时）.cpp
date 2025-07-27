#include <iostream>
using namespace std;
class time24
{
	public:
		time24();
		time24 (int h,int m,int s);
		void set_time(int h,int m,int s);
		void get_time (int &h, int &m, int &s);
		time24 operator+(int secs)const;
		time24 operator+(const time24 &t)const;
		time24 operator-(int secs)const;
		time24 operator-(const time24 &t)const;
	private:
		int hours,minutes,seconds;
};
time24::time24()
{
	hours=0;
	minutes=0;
	seconds=0;
}
time24::time24(int h,int m,int s)
{
	hours=h;
	minutes=m;
	seconds=s;
}
void time24::set_time(int h,int m,int s)
{
	hours=h;
	minutes=m;
	seconds=s;
}
void time24::get_time (int &h, int &m, int &s)
{
	h=hours;
	m=minutes;
	s=seconds;
}
time24 time24::operator+(int secs)const
{
		time24 temp;
	int h,m,s;
	h=hours+secs/3600;
	secs%=3600;
	m=minutes+secs/60;
	secs%=60;
	s=seconds+secs;
	m+=s/60;
	s%=60;
	h+=m/60;
	m%=60;
	h%=24;
	temp.hours=h;
	temp.minutes=m;
	temp.seconds=s;
	return temp;
}
time24 time24::operator+(const time24 &t)const
{
	int h,m,s;
	h=hours+t.hours;
	m=minutes+t.minutes;
	s=seconds+t.seconds;
	m+=s/60;
	s%=60;
	h+=m/60;
	m%=60;
	h%=24;
	time24 temp;
	temp.hours=h;
	temp.minutes=m;
	temp.seconds=s;
	return temp;
}
time24 time24::operator-(int secs)const
{
	int h,m,s;
	h=hours-secs/3600;
	secs%=3600;
	m=minutes-secs/60;
	secs%=60;
	s=seconds-secs;
	if(s<0)
	{
		s+=60;
		m--;
	}
	if(m<0)
	{
		m+=60;
		h--;
	}
	if(h<0)
	{
		h+=24;
	}
	time24 temp;
	temp.hours=h;
	temp.minutes=m;
	temp.seconds=s;
	return temp;
}
time24 time24::operator-(const time24 &t)const
{
	int h,m,s;
	h=hours-t.hours;
	m=minutes-t.minutes;
	s=seconds-t.seconds;
	if(s<0)
	{
		s+=60;
		m--;
	}
	if(m<0)
	{
		m+=60;
		h--;
	}
	if(h<0)
	{
		h+=24;
	}
	time24 temp;
	temp.hours=h;
	temp.minutes=m;
	temp.seconds=s;
	return temp;
}
	int main()
{

       int h, m, s, secs;

       time24 t1(0, 59, 57);

       time24 t2, t3;

       cin >> secs;

       t2 = t1 + secs;

       t2.get_time(h, m, s);

       cout << h << ':' << m << ':' << s << endl;

       t2 = t2 - secs;

       t2.get_time(h, m, s);

       cout << h << ':' << m << ':' << s << endl;
       cin >> h >> m >> s;

       t2.set_time(h, m, s);

       t3 = t1 + t2;

       t3.get_time(h, m, s);

       cout << h << ':' << m << ':' << s << endl;

       t1 = t3 - t2;

       t1.get_time(h, m, s);

       cout << h << ':' << m << ':' << s << endl;

}