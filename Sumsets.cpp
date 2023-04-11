#include <bits/stdc++.h>
using namespace std;

int a[1005];
int flag, ans;

int main() {
	int n;
	while(scanf("%d", &n), n) {
		set<int> num;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			num.insert(a[i]);
		}
		sort(a, a + n);
		
		flag = 0;
		ans = 2;
		for(int i = n - 1; i >= 0 && !flag; i--) {
			for(int j = 0; j < n && !flag; j++) {
				for(int k = j + 1; k < n && !flag; k++) {
					int tmp = a[i] - a[j] - a[k];
					if(i != j && i != k && tmp != a[i] && tmp != a[j] && tmp != a[k])
						if(num.count(tmp) ) {
							flag = 1;
							ans = a[i];
						}
				}
			}
		}
		if(flag) printf("%d\n", ans);
		else printf("no solution\n");
	}
	return 0;
}
