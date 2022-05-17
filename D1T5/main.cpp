#include <iostream>
#include <limits.h>
#include <windows.h>
//#include <stdlib.h>
//#include <time.h>
using namespace std;

class TRandom {
public:
	TRandom(long seed = 0) {
		mSeed = (seed ? seed : GetTickCount64());
	}
	void Seed(long seed = 0) {
		mSeed = (seed ? seed : GetTickCount64());
	}
	int Integer() {
		return Next();
	}
	int Integer(int min, int max) {
		return min + Next() % (max - min + 1);
	}
	double Real() {
		return double(Next() / double(INT_MAX));
	}
private:
	void Change() {
		mSeed = (314159267 * mSeed + 13579) % ULONG_MAX; //线性调和算法
	}
	int Next() {
		int loops = mSeed % 3;
		for (int i = 0; i <= loops; i++)
			Change();
		return int(mSeed / 2);
	}
	unsigned long mSeed;
};

/*
写的不好，不是随机洗牌，而是随机放牌了。
int isRepetitive(int, int*, int);
int main() {
	const int N = 54;
	int nums[N] = { -1 };
	memset(nums, -1, sizeof(nums));
	TRandom rand;
	for (int i = 0; i < N; i++) {
		int x = 0;
		do {
			x = rand.Integer(0, 53);
		} while (isRepetitive(x, nums, N));
		nums[i] = x;
	}
	for (int i = 0; i < N; i++)
		cout << nums[i] << " ";
	return 0;
}

int isRepetitive(int num, int arr[], int n) {
	for (int i = 0; i < n; i++)
		if (num == arr[i])
			return 1;
	return 0;
}
*/

//参考答案：
void swap(int&, int&);
int main() {
	const int N = 54; //牌数
	int cards[N] = { 0 };
	for (int i = 0; i < N; i++)
		cards[i] = i;
	TRandom rand;
	for (int i = 0; i < N; i++) {
		int pos = rand.Integer(i, 53);
		swap(cards[i], cards[pos]);
	}
	for (int i = 0; i < N; i++)
		cout << "Cards[" << i << "]=" << cards[i] << endl;
	return 0;
}

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

/*
采用伪随机数洗牌，无论洗多少张牌，排列都只有2^64种可能。
因为伪随机数发生器给定，应用的算法给定。
对指定的种子（seed）产生的伪随机数列就确定了，也就是洗牌后的结果定了。
而在64位平台上，seed是无符号长整型，最多有2^64种可能，它远远小于54!。
这也是商业加密算法不使用伪随机数加密的原因。
*/