#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int n = 100100;
bool isprime[n];

bool prime(int a){/*判斷是否是質數*/
	for(int i=2;i*i<=a;i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}

void primelist(){/*建表*/
	for(int i=0;i<n;i++){
		if(prime(i*i+i+41)){
			isprime[i]=true;/*如果這個數字產生的大數是質數，就在這個數字記為true*/ 
		}else{
			isprime[i]=false;
		}
	}
}

int main(){
	primelist();
	
	int a, b;
	while(cin>>a>>b){
		int s=0;
		for(int i=a;i<=b;i++){/*記錄在a,b範圍內有多少個質數產生*/
			if(isprime[i]){
				s++;
			}
		}
		double por=(double)s/(double)(b-a+1)*100+0.00000001;
		printf("%.2lf\n", por);
	}
	return 0;
}
