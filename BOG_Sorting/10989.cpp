#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
	return a < b;
}
int main() {
	int N;
	scanf_s("%d", &N);

	long long list

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &list[i]);
	}

	stable_sort(list.begin(), list.end(), cmp);

	for (int i = 0; i < N; i++) {
		printf("%d\n", list[i]);
	}
}

// 예전에 만들었던 코드 (code that I worte 8 months ago )
//#include <iostream>
//
//int main() {
//	int N;
//	int list[10001] = { 0, };
//
//	scanf("%d", &N);
//
//	int num;
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &num);
//		++list[num];
//	}
//
//	int k = 0;
//	while (k < 10001) {
//		while (list[k]) {
//			printf("%d\n", k);
//			--list[k];
//		}
//		k++;
//	}
//}