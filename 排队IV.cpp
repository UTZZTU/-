#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct people{
	int time;
	int age;
	int num;
};
int cmp(people a,people b)
{
	if(a.age<60&&a.age>6&&b.age<60&&b.age>6)
		return a.time<b.time;
	else if(a.age<=6&&b.age<=6)
	{
		if(a.age==b.age)
			return a.time<b.time;
		else
			return a.age<b.age;
	}
	else if(a.age>=60&&b.age>=60)
	{
		if(a.age==b.age)
			return a.time<b.time;
		else
			return a.age>b.age;
	}
	else if(a.age<=6||b.age<=6)
		return a.age<b.age;
	else 
		return a.age>b.age;
}
int main()
{
	int n;
	people a[30000];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a[i].num,&a[i].age);
		a[i].time=i;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	printf("%d\n",a[i].num);
	return 0;
} 

