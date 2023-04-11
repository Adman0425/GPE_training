#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#define Mlen 1000002

using namespace std;

int a[Mlen], b[Mlen];

int main(){
	int testcase, digit;
	int line=1;
	cin>>testcase;
	
	for(int i=0;i<testcase;i++){
		memset(a, 0, sizeof(a));/*初始化*/ 
		memset(b, 0, sizeof(b));
		
		cin>>digit;
		for(int j=1;j<=digit;j++){/*讀入各位數字並相加 !注意 ! 從一號位置開始，空出位置預留給可能的進位*/
			scanf("%d %d", &a[j], &b[j]);
			a[j]= a[j]+b[j];
		}
		for(int j=digit;j>=0;j--){/*處理進位*/
			if(a[j]>=10){
				a[j-1]+=(a[j]/10);
				a[j]%=10;
			}
		}
		if(line){/*第一次不須空行，之後則先空一行再輸出結果*/
			line=0;
		}else{
			cout<<endl;
		}
		if(a[0]==0){
			for(int j=1;j<=digit;j++){
				cout<<a[j];
			}
		}else{
			for(int j=0;j<=digit;j++){
				cout<<a[j];
			}
		}
	}
	
	return 0;
}
