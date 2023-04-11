#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> prime;
int visit[10240]={1, 1};/*0 and 1 aren't prime*/

void givePrime(){
	for(int i=2;i<=10240;i++){
		if(!visit[i]){
			for(int j=2;j*i<=10240;j++){
				visit[j*i]=1;
			}
			prime.push_back(i);/*prime has 2, 3, 5, 7, 11...*/
		}
	}
}

int main(){
	givePrime();
	
	int n;
	int len=prime.size();

	while(cin>>n && n!=0){
		int sol=0, sum=0;
		queue<int> ans;
		for(int i=0;i<len;i++){
			ans.push(prime[i]);
			sum+=prime[i];
			
			while(sum>n){
				sum-=ans.front();
				ans.pop();
			}
			if(sum==n){
				sol++;
			}
			if(prime[i]>n) break;
		}
		cout<<sol<<endl;
	}
	return 0;
}
