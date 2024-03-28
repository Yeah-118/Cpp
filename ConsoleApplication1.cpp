#include <iostream>
using namespace std;
int* ShellSort(int a[], int n) {
	// 对每组间隔为 h的分组进行排序，刚开始 h = n / 2;
	for (int h = n / 2; h > 0; h /= 2)
	{
		//对各个局部分组进行插入排序
		for (int i = h; i < n; i++)
		{
			int temp = a[i];
			int k;
			for (k = i; k >= h && a[k - h] > temp; k -= h)
			{
				a[k] = a[k - h];
			}
			a[k] = temp;

		}
	}
	return a;
}
int* InsertSort(int a[], int n) {
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int k = i - 1;
		while (k >= 0 && a[k] > temp)
		{
			k--;
		}
		for (int j = i; j > k + 1; j--)
		{
			a[j] = a[j - 1];
		}
		a[k + 1] = temp;
	}
	return a;
}

int* SelectSorting(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min] > a[j]) {
				min = j;
			}
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	return a;
}
int* BubbleSorting(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	return a;
}
void PrintArrays(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
}
int main()
{
	cout << "Hello World!\n";
	int arr[] = { 6,5,1,9,8,7 };
	cout << "排序前\n";
	PrintArrays(arr, 6);
	cout << "排序后\n";
	int* newarr = ShellSort(arr, 6);
	PrintArrays(newarr, 6);
	//	return 0;
}
