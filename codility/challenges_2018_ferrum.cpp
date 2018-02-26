#include<vector>
#include<iostream>
#include<map>
using namespace std;

int solution1(vector<int>& A)
{
	int cnt = 0;
	int N = A.size();
	int* tmp = new int[N];
	for (int i = 0; i < N; i++) {
		tmp[i] = A[i];
		if (tmp[i] > -1 && cnt == 0)
			cnt = 1;
		for (int j = i + 1; j < N; j++) {
			tmp[j] = tmp[j - 1] + A[j];
			if (tmp[j] > -1 && j - i + 1 > cnt)
				cnt = j - i + 1;
		}
	}
	delete[] tmp;
	return cnt;
}

int solution2(vector<int>& A)
{
	int cnt = 0;
	int sum = 0;
	map<int, int> sumidx;
	for (int i = 0; i <A.size(); i++) {
		sum += A[i];
		if (sum >= 0) {
			cnt = i + 1;
		}
		else {
			if (sumidx.find(sum) != sumidx.end()) {
				int tt = i - sumidx[sum];
				cnt = cnt > tt ? cnt : tt;
			}
			else
				sumidx[sum] = i;
		}
	}
	return cnt;
}
