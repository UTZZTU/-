//归并排序
//首先将初始序列的n个元素看成是n个有序的子序列，每个子序列的长度为1，
//然后两两归并，得到n/2个长度为2的有序子序列，在此基础上，再对长度为2
//的有序子序列进行两两归并，得到若干个长度为4的有序子序列，以此类推，直
//到得到一个长度为n的有序序列为止
#include<iostream>
#include<algorithm>
using namespace std;
void work1(int *ar, int size)
{
	int *a = ar;
	int *b = new int[size];
	for (int seg = 1; seg < size; seg += seg) 
	{
		for (int start = 0; start < size; start += seg + seg) 
		{
			int low = start, mid = min(start + seg, size), high = min(start + seg + seg, size);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		int *temp = a;
		a = b;
		b = temp;
	}
	if (a != ar) 
	{
		for (int i = 0; i < size; i++)
			b[i] = a[i];
		b = a;
	}
	delete[] b;
}
void test()
{
	int a[] = { 17,3 ,42,39,10,6,64,72,48 };
	int a_size;
	a_size = sizeof(a) / sizeof(int);
	work1(a, a_size);
	for (int i = 0; i < a_size; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}
int main()
{
	test();
	return 0;
}

//第一步：先将相邻的两个元素两两排序，
//第二步：将相邻的四个元素两两排序，
//第三步：将相邻的八个元素两两排序，
//			.........
//			.........
//依此类推
