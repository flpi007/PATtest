#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
const int N = 17;
int rad1;
vector<int> n1, n2;
void init(char *a, vector<int> &vec) {
	for (char *s = a; *s; s++) {
		if (isdigit(*s)) {
			vec.push_back(*s - '0');
		} else if (islower(*s)) {
			vec.push_back(*s - 'a' + 10);
		}
	}
	reverse(vec.begin(), vec.end());
}
int check(ll a, ll radix, vector<int> &vec) {
	ll t = 0;
	for (int i = vec.size() - 1; i >= 0; i--) {
		t = t * radix + vec[i];
		if (t > a) {
			return 1;
		}
	}
	if (t == a) {
		return 0;
	} else {
		return -1;
	}
}
int main() {
	char a[N], b[N];
	int tag;
	scanf("%s %s %d %d", a, b, &tag, &rad1);
	if (tag == 1) {
		init(a, n1);
		init(b, n2);
	} else if(tag == 2){
		init(b, n1);
		init(a, n2);
	}
	int max2 = 0;
	for (int i = 0; i < n2.size(); i++) {
		max2 = max(max2, n2[i]);
	}
	ll aa = 0, bb = 0;
	for (int i = n1.size()-1; i >=0; i--) {
		aa = aa * rad1 + n1[i];
	}
	// printf("a:%lld\n", aa);
	if (n2.size() == 1) {
		if (n2[0] == aa) {
			printf("%d\n", max2 + 1);
			return 0;
		}
	} else if(n2.size() > 1){
		ll front = max2 + 1, tail = aa + 1;
		while (front < tail) {
			ll p = (front + tail) / 2;
			// printf("p:%d\n", p);
			int t = check(aa, p, n2);
			if (t == -1) {
				front = p + 1;
			} else if(t == 1){
				tail = p;
			} else if (t == 0) {
				printf("%lld\n", p);
				return 0;
			}
		}
	}
	printf("Impossible\n");
	return 0;
}