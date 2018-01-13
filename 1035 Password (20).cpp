#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int M = 17, L = 4;
const char MOD[L] = {
	'1', '0', 'l', 'O',
};
const char REP[L] = {
	'@', '%', 'L', 'o',
};
struct Log
{
	char name[M], code[M];
	Log(char *n, char *c) {
		strcpy(name, n);
		strcpy(code, c);
	}
	bool modify() {
		bool modi = false;
		for (char *s = code; *s; s++) {
			for (int i = 0; i < L; i++) {
				if (*s == MOD[i]) {
					modi = true;
					*s = REP[i];
				}
			}
		}
		return modi;
	}
};
int n;
vector<Log> logs;
vector<int> modify;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a[M], b[M];
		cin >> a >> b;
		Log log = Log(a, b);
		if (log.modify()) {
			modify.push_back(i);
		}
		logs.push_back(log);
	}
	if (modify.size() == 0) {
		if (n == 1) {
			printf("There is 1 account and no account is modified\n");
		}
		else {
			printf("There are %d accounts and no account is modified\n", n);
		}
	}
	else {
		printf("%d\n", modify.size());
		for (int i = 0; i < modify.size(); i++) {
			printf("%s %s\n", logs[modify[i]].name, logs[modify[i]].code);
		}
	}
	return 0;
}