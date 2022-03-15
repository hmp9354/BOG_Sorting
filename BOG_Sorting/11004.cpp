#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int K;
	scanf_s("%d %d", &N, &K);

	int* list = new int[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &list[i]);
	}

	sort(list, list + N);

	printf("%d", list[K - 1]);
}