#include<bits/stdc++.h>//包含C++几乎所有头文件的文件 
using namespace std;
int main()
{
	//三角形，a,b,c    abs(a-b)<c<a+b 
	int n,p,a[100002],b,left,right;
	long long int sum=0;//100000*99999超出了int 
	cin>>n>>p;
	for(b=0;b<n;b++)
	cin>>a[b];
	sort(a,a+n);//时间复杂度：nlog2n 
	for(b=0;b<n;b++)
	{
		/*a+b+1,a+n限定范围：a[b+1]---a[n-1]
		此范围下:
		找第一个大于abs(p-a[b]的数，用upper
		找第一个>= p+a[b]的数,用lower。是为间接找出最后一个<p+a[b]
		的数，二者下标差1.*/ 
		left=upper_bound(a+b+1,a+n,abs(p-a[b]))-a;//> 
		right=lower_bound(a+b+1,a+n,p+a[b])-a;//>=
		sum+=right-left;
	}
	cout<<sum;
	return 0;
}