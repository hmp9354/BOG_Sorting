#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	string name;
	int kor;
	int eng;
	int math;
};

bool cmp(Student u, Student v) {
	if (u.kor == v.kor) {
		if (u.eng == v.eng) {
			if (u.math == v.math) {
				return u.name < v.name;
			}
			else { return u.math > v.math; }
		}
		else { return u.eng < v.eng; }
	}
	else {
		return u.kor > v.kor;
	}
}

int main() {
	int N;
	cin >> N;

	vector<Student> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i].name >> vec[i].kor >> vec[i].eng >> vec[i].math;
	}

	stable_sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << vec[i].name << "\n";
	}

}