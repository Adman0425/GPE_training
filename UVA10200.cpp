#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int n = 100100;
bool isprime[n];

bool prime(int a){/*�P�_�O�_�O���*/
	for(int i=2;i*i<=a;i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}

void primelist(){/*�ت�*/
	for(int i=0;i<n;i++){
		if(prime(i*i+i+41)){
			isprime[i]=true;/*�p�G�o�ӼƦr���ͪ��j�ƬO��ơA�N�b�o�ӼƦr�O��true*/ 
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
		for(int i=a;i<=b;i++){/*�O���ba,b�d�򤺦��h�֭ӽ�Ʋ���*/
			if(isprime[i]){
				s++;
			}
		}
		double por=(double)s/(double)(b-a+1)*100+0.00000001;
		printf("%.2lf\n", por);
	}
	return 0;
}
