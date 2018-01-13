#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100007;
int np, nc;
int coupon[N], product[N];
int main() {
	scanf("%d", &nc);
	for (int i = 0; i < nc; i++) {
		scanf("%d", &coupon[i]);
	}
	scanf("%d", &np);
	for (int i = 0; i < np; i++) {
		scanf("%d", &product[i]);
	}
	sort(coupon, coupon + nc);
	sort(product, product + np);
	int ans = 0;
	for (int i = nc - 1, j = np - 1; \
		i >= 0 && j >= 0 && coupon[i] >= 0 && product[j] >= 0; i--, j--) {
		ans += coupon[i] * product[j];
	}
	for (int i = 0, j = 0; \
		i < nc && j < np && coupon[i] < 0 && product[j] < 0; i++, j++) {
		ans += coupon[i] * product[j];
	}
	printf("%d\n", ans);
	return 0;
}