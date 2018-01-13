#include <cstdio>
#include <cstring>
using namespace std;

const int M = 20;
int main() {
	int n, grade[2];
	char name[2][M], clas[2][M];
	memset(grade, -1, sizeof(grade));
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		char nam[M], gen, cla[M];
		int gra;
		scanf("%s %c %s %d\n", nam, &gen, cla, &gra);
		if (gen == 'M') {
			if (grade[0] == -1 || gra < grade[0]) {
				grade[0] = gra;
				strcpy(name[0], nam);
				strcpy(clas[0], cla);
			}
		} else {
			if (grade[1] == -1 || gra > grade[1]) {
				grade[1] = gra;
				strcpy(name[1], nam);
				strcpy(clas[1], cla);
			}
		}
	}
	if (grade[1] != -1) {
		printf("%s %s\n", name[1], clas[1]);
	} else {
		printf("Absent\n");
	}
	if (grade[0] != -1) {
		printf("%s %s\n", name[0], clas[0]);
	} else {
		printf("Absent\n");
	}
	if (grade[0] != -1 && grade[1] != -1) {
		printf("%d\n", grade[1] - grade[0]);
	} else {
		printf("NA\n");
	}
	return 0;
}