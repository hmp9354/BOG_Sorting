#include <iostream>

void merge(int* X, int* Y, int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		merge(X, Y, left, mid);
		merge(X, Y, mid + 1, right);

		int lnum = left;
		int rnum = mid + 1;

		int* Xlist = new int[right - left + 1];
		int* Ylist = new int[right - left + 1];

		int i = 0;
		while (lnum <= mid || rnum <= right) {
			if (lnum > mid) {
				Xlist[i] = X[rnum];
				Ylist[i] = Y[rnum];
				rnum++;
				i++;
			}
			else if (rnum > right) {
				Xlist[i] = X[lnum];
				Ylist[i] = Y[lnum];
				lnum++;
				i++;
			}
			else if (X[lnum] == X[rnum]) {
				if (Y[lnum] <= Y[rnum]) {
					Xlist[i] = X[lnum];
					Ylist[i] = Y[lnum];
					lnum++;
					i++;
				}
				else {
					Xlist[i] = X[rnum];
					Ylist[i] = Y[rnum];
					rnum++;
					i++;
				}

			}
			else if (X[lnum] < X[rnum]) {
				Xlist[i] = X[lnum];
				Ylist[i] = Y[lnum];
				lnum++;
				i++;
			}
			else {
				Xlist[i] = X[rnum];
				Ylist[i] = Y[rnum];
				rnum++;
				i++;
			}
		}

		for (int i = 0; i <= right - left; i++) {
			X[left + i] = Xlist[i];
			Y[left + i] = Ylist[i];
		}
	}
}

int main() {
	int N;
	scanf_s("%d", &N);

	int* X = new int[N];
	int* Y = new int[N];

	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &X[i], &Y[i]);
	}

	merge(X, Y, 0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", X[i], Y[i]);
	}
}

