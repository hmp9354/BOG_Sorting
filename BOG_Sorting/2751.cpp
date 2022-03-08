#include <iostream>

void merge(int list[], int left, int right);

int main() {
	int N;
	scanf_s("%d", &N);

	int* list = new int[N];

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &list[i]);
	}

	merge(list, 0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", list[i]);
	}
}

void merge(int* list, int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		merge(list, left, mid);
		merge(list, mid + 1, right);

		int lnum = left;
		int rnum = mid + 1;

		int* tmpList = new int[right - left + 1];

		int i = 0;
		while (lnum <= mid || rnum <= right) {
			if (lnum > mid) {
				tmpList[i] = list[rnum];
				rnum++;
				i++;
			}
			else if (rnum > right) {
				tmpList[i] = list[lnum];
				lnum++;
				i++;
			}
			else if (list[lnum] <= list[rnum]) {
				tmpList[i] = list[lnum];
				lnum++;
				i++;
			}
			else {
				tmpList[i] = list[rnum];
				rnum++;
				i++;
			}
		}

		for (int i = 0; i <= right - left; i++) {
			list[left + i] = tmpList[i];
		}
	}	
}