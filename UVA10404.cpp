#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

int n, m;
int dp[1000000], val[20];
int main(){
	while(cin>>n>>m){
		memset(dp, 0, sizeof(dp));
		memset(val, 0, sizeof(val));
		
		for(int i=0;i<m;i++){
			cin>>val[i];
		}
		for(int a=1;a<=n;a++){
			for(int b=0;b<m;b++){
				if(a-val[b]>=0 && !dp[a-val[b]]){
					dp[a]=1;
					break;
				}
			}
		}
		cout<<((dp[n]==1)?"Stan wins":"Ollie wins");
		cout<<endl;
	}
	return 0;
}
