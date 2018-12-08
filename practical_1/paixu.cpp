#include <iostream>
#include <string>

using namespace std;

template<class T>
void insertion_sort(T arry[],int n)//插入排序
{
	for (int j=1;j<n;j++)
	{
		T key = arry[j];
		int i=0;
		for (i=(j-1);i >= 0 && key<arry[i];i--)
		{
			arry[i + 1] = arry[i];
		}
		arry[i+1] = key;
	}
}
//所以这个排序方式，总的时间复杂度为（n-1）*n/2  元素移动为2n
template<class T>
void rank_sort(T name[],int n,T rand[])//将数组变成名次输出,所以时间复杂度为：1+2+3+4...+n-1=(n-1)*n/2
{
	for (int i = 0; i < n; i++)
		rand[i] = 0;
	for (int i = 1; i < n; i++)//一共有n-1次循环
	{
		for (int j = 0; j < i; j++)//针对每一次循环都有i-1次小循环
		{
			if (name[i] >= name[j])
			{
				rand[i]++;
			}
			else
			{
				rand[j]++;
			}
		}
	}

	T *u = new T [n];
	for (int i=0;i<n;i++)//循环次数为n
	{
		u[rand[i]] = name[i];
	}
	for (int i=0;i<n;i++)//循环次数为n
	{
		name[i] = u[i];
	}
	delete[]u;
}

template<class T>
void show_array(T arry[],int n)
{
	for (int i=0;i<n;i++)
	{
		cout << arry[i] << "   ";
	}
}

template<class T>
int length(T& arry)
{
	return sizeof(arry) / sizeof(arry[0]);
}

template<class T>
int indexOfMax(T a[],int n)//找出最大的数在数组之中,这个的时间复杂度是n，随n的数值在变化
{
	int temp = a[0];
	int m = 0;
	for (int i=0;i<n;i++)
	{
		if (temp<=a[i])
		{
			temp = a[i];
			m = i;
		}
	}
	return m;
}

//所以这种排序方法的时间复杂度为(n-1)*n/2,但是元素移动次数为3(n-1)次
template<class T>
void selectionSort(T arry[],int n)//首先找出最大的数，把他放在n-1的位置上，然后找出次高的数，放在n-2的位置上，以此类推
{
	for(int i=n;i>1;i--)//执行n-1次，所以这种排序方法，最坏时间复杂度为(n-1)*n/2
	{
		int j = indexOfMax(arry,i);//每次内循环都是size-1次
		swap(arry[j],arry[i-1]);//交换的时候，每次交换都要进行3次元素移动
	}
}

template<class T>//将最大的数放到数组的最右边
void bubble(T a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])//由于和i+1进行比较和交换，所以不能用n
		{
			swap(a[i], a[i + 1]);//进行3次元素移动
		}
	}
}

template<class T>
void bubbleSort(T a[],int n)
{
	for(int i=n;i>1;i--)
	{
		bubble(a, i);
	}
}



void main()
{
	int arry[] = {7,8,5,9,6,4,3,2,1};
	//int rand[] = { 7,8,7,4,6,4,3,2,1 };
	//string name[] = {"temp","jim","lilith","mike","kikko"};
	int n = length(arry);
	//cout << "测试最大数是：" << indexOfMax(arry,n) << endl;
	bubbleSort(arry, n);
	//cout << "输出现在的数组" << endl;
	//showArray(arry,n);
	//rank_sort(arry,n,rand);
	//cout << "\n输出名次:" << endl;
	//showArray(rand,n);
	////Insertion_sort(arry,n);
	cout << "\n输出排序之后的数组：" << endl;
	show_array(arry, n);
	system("pause");
}
