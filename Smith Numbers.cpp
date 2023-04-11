#include <iostream>
#include <cstdlib>
#include <cstring> 

using namespace std;

int testcase, n, a=0;
bool isPrime[100005];/*記錄每一個數是否是質數*/ 
int prime[10000];/*紀錄質數*/ 

int digsum(int num){/*記錄各位數字和*/
	int sum=0;
	while(num!=0){
		sum+= num%10;
		num/=10;
	}
	return sum;
}

int main(){
	memset(isPrime, true, sizeof(isPrime));/*初始化*/
	isPrime[0]=isPrime[1]=false;/*0和1不是質數*/ 
	
	for(int i=2;i<=10000;i++){/*做質數表*/ 
		if(isPrime[i]){
			prime[a++]=i;
			for(int j=i*i;j<=10000;j+=i){
				isPrime[j]=false;
			}
		}
	}
	
	cin>>testcase;
	while(testcase--){
		cin>>n;
		for(int u=n+1;;u++){
			if(u<=10000 && isPrime[u]) continue;/*比10000小而且本身是質數就不算*/ 
			
			int sum1, sum2, tmp=u;
			sum1=sum2=0;
			
			sum1=digsum(u);/*各位數字的總和*/ 
			
			for(int i=0;i<=a && tmp>=prime[i];i++){/*質數表還沒到盡頭，而且數字還比目前的質數大*/ 
				while(tmp%prime[i]==0){/*為了處理可能會有質數次方的情況，所以要用while而不是if*/ 
					tmp /= prime[i];
					sum2+=digsum(prime[i]);
				}
			}
			if(tmp==u) continue;/*沒有找到質因數*/ 
			if(tmp!=1) sum2+=digsum(tmp);/*如果最後沒有除盡*/ 
			
			if(sum1==sum2){
				cout<<u<<endl;
				break;
			}
		}
	}
	
	return 0; 
}
