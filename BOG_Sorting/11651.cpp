#include <iostream>

void merge(int* X, int* Y, int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		merge(X, Y, left, mid);
		merge(X, Y, mid+1, right);

		int lnum = left;
		int rnum = mid + 1;

		int* tmpX = new int[right - left + 1];
		int* tmpY = new int[right - left + 1];

		int i = 0;
		while (lnum <= mid || rnum <= right) {
			if (lnum > mid) {
				tmpX[i] = X[rnum];
				tmpY[i] = Y[rnum];
				rnum++;
				i++;
			}
			else if (rnum > right) {
				tmpX[i] = X[lnum];
				tmpY[i] = Y[lnum];
				lnum++;
				i++;
			}
			else if (Y[lnum] == Y[rnum]) {
				if (X[lnum] < X[rnum]) {
					tmpX[i] = X[lnum];
					tmpY[i] = Y[lnum];
					lnum++;
					i++;
				}
				else {
					tmpX[i] = X[rnum];
					tmpY[i] = Y[rnum];
					rnum++;
					i++;
				}
			}
			else if (Y[lnum] < Y[rnum]) {
				tmpX[i] = X[lnum];
				tmpY[i] = Y[lnum];
				lnum++;
				i++;
			}
			else {
				tmpX[i] = X[rnum];
				tmpY[i] = Y[rnum];
				rnum++;
				i++;
			}
		}

		for (int i = 0; i <= right - left; i++) {
			X[left + i] = tmpX[i];
			Y[left + i] = tmpY[i];

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