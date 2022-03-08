#include <iostream>
//#include <string>
using namespace std;


void merge(int* age, int* num, string* name, int left, int right) {
	int mid = (left + right) / 2;

	if (left < right) {
		merge(age, num, name, left, mid);
		merge(age, num, name, mid + 1, right);

		int lnum = left;
		int rnum = mid + 1;

		int* tmpAge = new int[right - left];
		int* tmpNum = new int[right - left];
		string* tmpName = new string[right - left];

		int i = 0;
		while (lnum <= mid || rnum <= right) {
			if (lnum > mid) {
				tmpAge[i] = age[rnum];				
				tmpName[i] = name[rnum];
				rnum++;
				i++;
			}
			else if (rnum > right) {
				tmpAge[i] = age[lnum];				
				tmpName[i] = name[lnum];
				lnum++;
				i++;
			}
			else if (age[lnum] == age[rnum]) {
				if (num[lnum] < num[rnum]) {
					tmpAge[i] = age[lnum];					
					tmpName[i] = name[lnum];
					lnum++;
					i++;
				}
				else {
					tmpAge[i] = age[rnum];					
					tmpName[i] = name[rnum];
					rnum++;
					i++;
				}
			}
			else if (age[lnum] < age[rnum]) {
				tmpAge[i] = age[lnum];				
				tmpName[i] = name[lnum];
				lnum++;
				i++;
			}
			else {
				tmpAge[i] = age[rnum];				
				tmpName[i] = name[rnum];
				rnum++;
				i++;
			}
		}


		for (int i = 0; i <= right - left; i++) {
			age[left + i] = tmpAge[i];			
			name[left + i] = tmpName[i];
		}
	}
}
int main() {
	int N;
	cin >> N;
	
	int* age = new int[N];
	string* name = new string[N];
	int* num = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> age[i] >> name[i];
		num[i] = i + 1;
	}

	merge(age, num, name, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << age[i] << name[i] << "\n";
	}
}