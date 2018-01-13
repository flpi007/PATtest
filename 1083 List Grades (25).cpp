#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

struct Stu
{
	string name, id;
	Stu(string &n, string &i) {
		name = n;
		id = i;
	}
};
int n;
int idx[200];
int main() {
	vector<Stu> stus;
	cin >> n;
	for (int i = 0; i < n; i++) {
		// printf("%d\n", i);
		string name, id;
		int grade;
		cin >> name >> id >> grade;
		stus.push_back(Stu(name, id));
		idx[grade] = stus.size();
	}
	int gmin, gmax, cnt = 0;
	cin >> gmin >> gmax;
	for (int i = gmax; i >= gmin; i--) {
		if (idx[i] != 0) {
			cnt++;
			Stu &s = stus[idx[i]-1];
			printf("%s %s\n", s.name.c_str(), s.id.c_str());
		}
	}
	if (cnt == 0) {
		printf("NONE\n");
	}
	return 0;
}