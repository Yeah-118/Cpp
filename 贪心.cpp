#include <iostream>  
#include <vector>  
#include <math.h>
using namespace std;
#define DEBUG 0  
//台阶问题
#if DEBUG ==1
int  queue[1000];
int index;
void output() {
	for (int i = 0;i < index;i++)
	{
		cout << queue[i] << " ";
	}
	cout << endl;
}
void step(int n) {
	if (n == 0) {
		output();
		return;
	}
	queue[index++] = 1;
	step(n - 1);
	--index;
	if (n > 1) {
		queue[index++] = 2;
		step(n - 2);
		--index;
	}
	if (n > 2) {
		queue[index++] = 3;
		step(n - 3);
		--index;
	}
}

int main()
{
	int n;
	cout << "一共多少阶" << endl;
	cin >> n;
	step(n);
}
#endif
//最大公约数
#if DEBUG==2
int gcd(int x, int y) {
	if (x == y) { return x; }
	else {
		if (x > y) {
			return(y, x % y);
		}
		else
		{
			return(x, y % x);
		}
	}
}
int main() {
	while (true)
	{
		int x, y, z;
		cin >> x >> y;
		z = gcd(x, y);
		cout << x << "和" << y << "最大公约数" << z;
	}
}
#endif
//排队打水问题
#if DEBUG==3
int MinWait(int a[], int n, int count) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1]) {
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
	int sum = 0;
	int groud = n / count;
	for (int i = 0; i < n; i++)
	{
		int timer = i / count;

		sum += a[i] * (groud - timer);
	}
	return sum;
}
int  main() {
	int n, r;
	cout << "输入打水人数(小于100)和水龙头个数\n";
	cin >> n >> r;
	int s[100];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	int mintime = MinWait(s, n, r);
	cout << "最小等待时间\n" << mintime;
#endif
	//均分纸牌
#if DEBUG==4
	void moveCards(vector<int>&piles, int n) {
		int totalCards = 0;
		for (int cards : piles) {
			totalCards += cards;
		}
		int targetCards = totalCards / n;
		cout << targetCards;
		int moves = 0;
		for (int i = 0; i < n - 1; ++i) {
			int diff = piles[i] - targetCards;
			piles[i] -= diff;
			piles[i + 1] += diff;
			int time;
			if (diff >= 0) { time = diff; }
			else
			{
				time = -diff;
			}
			moves += time;
		}
		cout << "Total moves: " << moves << endl;
	}

	int main() {
		int n = 4;
		vector<int> piles = { 9, 8, 17, 6 };
		for (int cards : piles) {
			cout << cards << " ";
		}
		moveCards(piles, n);
		// 输出每堆纸牌移动后的结果
		for (int cards : piles) {
			cout << cards << " ";
		}
		cout << endl;
		return 0;
	}
#endif
	//金银岛
#if DEBUG==5
	struct Metal {
		int Weight;
		int Value;
		float ValuePerWeight;
	};
	int main() {
		cout << "背包的最大容量";
		int w;
		cin >> w;
		cout << "多少种珠宝";
		int k = 0;
		cin >> k;
		int currentWeight = 0;
		double maxValue = 0;
		Metal metals[100];
		for (int i = 0; i < k; i++)
		{
			cout << "珠宝的重量和价值";
			cin >> metals[i].Weight >> metals[i].Value;
			metals[i].ValuePerWeight = (float)(metals[i].Value) / metals[i].Weight;
		}
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k - i - 1; j++)
			{
				if (metals[j].ValuePerWeight < metals[j + 1].ValuePerWeight) {
					Metal temp = metals[j + 1];
					metals[j + 1] = metals[j];
					metals[j] = temp;
				}
			}
		}
		for (int i = 0; i < k; i++)
		{
			int takeweight = min(metals[i].Weight, w - currentWeight);
			maxValue += takeweight * metals[i].ValuePerWeight;
			currentWeight += takeweight;
			if (currentWeight == w) {
				break;
			}
		}
		cout << "最大价值" << maxValue << endl;
	}
#endif
	//最小新整数
#if DEBUG==6
	int NewInteger(int num, int cut)
	{
		int arr[10];
		int index = 0;
		while (true)
		{
			arr[index] = num % 10;
			num /= 10;
			index++;
			if (num == 0) { break; }
		}
		for (int i = 0; i < index; i++)
		{
			for (int j = 0; j < index - i - 1; j++)
			{
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < index - cut; i++)
		{
			sum += arr[i] * pow(10, (index - cut - i - 1));
		}
		return sum;
	}
	int main() {
		cout << "输入一个正整数n(0<n<1000000000)，每个数位上数字均不为0\n";
		int number, k;
		cin >> number;
		cout << "从m位中删除k位(0<k<m)\n";
		cin >> k;
		int newint = NewInteger(number, k);
		cout << "最小新整数\n" << newint << endl;
	}
#endif
#if (DEBUG==0) 
	int main() {
		cout << "没有写功能！";
	}
#endif