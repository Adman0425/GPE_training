#include <bits/stdc++.h>

using namespace std;

int money[]={10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
long long dp[30005]={1};

int main(){
	
	for(int i=10;i>=0;i--){
		for(int j=money[i];j<=30000;j++){
			dp[j]+=dp[j-money[i]];
		}
	}
	
	int p, q;
	while(scanf("%d.%d", &p, &q)!=EOF && !(p==0 && q==0)){
		printf("%3d.%02d%17lld\n", p, q, dp[p*100+q]);
	}
	return 0;
}
