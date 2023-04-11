#include <bits/stdc++.h>

using namespace std;

int w[22], dp[202];

int main(){
	int testcase;
	cin>>testcase;
	while(testcase--){
		
		memset(dp, 0, sizeof(dp));
		dp[0]=1;/*w=0 definitely can divide equally*/
		
		int count=0, sum=0;
		char ch;
		while(~scanf("%d%c", &w[count], &ch) && ch==' '){/*scanf fails return -1, succeed return 0*/
			sum+=w[count];
			count++;
		}
		sum+=w[count];
		for(int i=0;i<=count;i++){
			for(int j=sum;j>=w[i];j--){
				if(dp[j-w[i]]){
					dp[j]=1;/*weight on one side*/
				}
			}
		}
		
		if(sum%2 || !dp[sum/2]){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}


