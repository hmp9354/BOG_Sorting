#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(long long a, long long b) {
	return a < b;
}
int main() {
	int N;
	scanf_s("%d", &N);

	vector<long long>list(N);
	list.clear();
	
	long long tmp;
	for (int i = 0; i < N; i++) {
		scanf_s("%lld", &tmp);		
		list.push_back(tmp);
	}	
	
	stable_sort(list.begin(), list.end(), cmp);	

	int many = 0;
	long long result = list[0];
	int num = 1;
	for (int i = 1; i < N; i++) {	
		if (list[i] == list[i - 1]) {
			num++;
		}
		else {
			if (many < num) {
				many = num;				
				result = list[i - 1];
			}
			num = 1;
		}
	}

	if (many < num) {
		many = num;
		num = 1;
		result = list[N-1];
	}

	printf("%lld", result);
}