#include <bits/stdc++.h>

using namespace std;

const int maxn=10;
const int per[maxn]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
double a[maxn], p[maxn];

int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%lf", &a[i]);
		}
		int cnt=per[n];
		double ans=1e9;
		while(cnt--){/*all combinations*/
			p[0]=a[0];
			double cur=2*a[0];
			for(int i=0;i<n;i++){
				p[i]=a[i];
				for(int j=0;j<i;j++){
					p[i]=max(p[i], p[j]+2*sqrt(a[i]*a[j]));
				}
				cur=max(cur, p[i]+a[i]);
			}
			ans=min(ans, cur);
			next_permutation(a, a+n);
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
