#include <iostream>
#include <cstdlib>
#include <cstring> 

using namespace std;

int testcase, n, a=0;
bool isPrime[100005];/*�O���C�@�ӼƬO�_�O���*/ 
int prime[10000];/*�������*/ 

int digsum(int num){/*�O���U��Ʀr�M*/
	int sum=0;
	while(num!=0){
		sum+= num%10;
		num/=10;
	}
	return sum;
}

int main(){
	memset(isPrime, true, sizeof(isPrime));/*��l��*/
	isPrime[0]=isPrime[1]=false;/*0�M1���O���*/ 
	
	for(int i=2;i<=10000;i++){/*����ƪ�*/ 
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
			if(u<=10000 && isPrime[u]) continue;/*��10000�p�ӥB�����O��ƴN����*/ 
			
			int sum1, sum2, tmp=u;
			sum1=sum2=0;
			
			sum1=digsum(u);/*�U��Ʀr���`�M*/ 
			
			for(int i=0;i<=a && tmp>=prime[i];i++){/*��ƪ��٨S����Y�A�ӥB�Ʀr�٤�ثe����Ƥj*/ 
				while(tmp%prime[i]==0){/*���F�B�z�i��|����Ʀ��誺���p�A�ҥH�n��while�Ӥ��Oif*/ 
					tmp /= prime[i];
					sum2+=digsum(prime[i]);
				}
			}
			if(tmp==u) continue;/*�S������]��*/ 
			if(tmp!=1) sum2+=digsum(tmp);/*�p�G�̫�S������*/ 
			
			if(sum1==sum2){
				cout<<u<<endl;
				break;
			}
		}
	}
	
	return 0; 
}
