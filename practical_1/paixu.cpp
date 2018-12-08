#include <iostream>
#include <string>

using namespace std;

template<class T>
void insertion_sort(T arry[],int n)//��������
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
//�����������ʽ���ܵ�ʱ�临�Ӷ�Ϊ��n-1��*n/2  Ԫ���ƶ�Ϊ2n
template<class T>
void rank_sort(T name[],int n,T rand[])//���������������,����ʱ�临�Ӷ�Ϊ��1+2+3+4...+n-1=(n-1)*n/2
{
	for (int i = 0; i < n; i++)
		rand[i] = 0;
	for (int i = 1; i < n; i++)//һ����n-1��ѭ��
	{
		for (int j = 0; j < i; j++)//���ÿһ��ѭ������i-1��Сѭ��
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
	for (int i=0;i<n;i++)//ѭ������Ϊn
	{
		u[rand[i]] = name[i];
	}
	for (int i=0;i<n;i++)//ѭ������Ϊn
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
int indexOfMax(T a[],int n)//�ҳ�������������֮��,�����ʱ�临�Ӷ���n����n����ֵ�ڱ仯
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

//�����������򷽷���ʱ�临�Ӷ�Ϊ(n-1)*n/2,����Ԫ���ƶ�����Ϊ3(n-1)��
template<class T>
void selectionSort(T arry[],int n)//�����ҳ�����������������n-1��λ���ϣ�Ȼ���ҳ��θߵ���������n-2��λ���ϣ��Դ�����
{
	for(int i=n;i>1;i--)//ִ��n-1�Σ������������򷽷����ʱ�临�Ӷ�Ϊ(n-1)*n/2
	{
		int j = indexOfMax(arry,i);//ÿ����ѭ������size-1��
		swap(arry[j],arry[i-1]);//������ʱ��ÿ�ν�����Ҫ����3��Ԫ���ƶ�
	}
}

template<class T>//���������ŵ���������ұ�
void bubble(T a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])//���ں�i+1���бȽϺͽ��������Բ�����n
		{
			swap(a[i], a[i + 1]);//����3��Ԫ���ƶ�
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
	//cout << "����������ǣ�" << indexOfMax(arry,n) << endl;
	bubbleSort(arry, n);
	//cout << "������ڵ�����" << endl;
	//showArray(arry,n);
	//rank_sort(arry,n,rand);
	//cout << "\n�������:" << endl;
	//showArray(rand,n);
	////Insertion_sort(arry,n);
	cout << "\n�������֮������飺" << endl;
	show_array(arry, n);
	system("pause");
}
