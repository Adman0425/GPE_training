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
		memset(a, 0, sizeof(a));/*��l��*/ 
		memset(b, 0, sizeof(b));
		
		cin>>digit;
		for(int j=1;j<=digit;j++){/*Ū�J�U��Ʀr�ìۥ[ !�`�N ! �q�@����m�}�l�A�ťX��m�w�d���i�઺�i��*/
			scanf("%d %d", &a[j], &b[j]);
			a[j]= a[j]+b[j];
		}
		for(int j=digit;j>=0;j--){/*�B�z�i��*/
			if(a[j]>=10){
				a[j-1]+=(a[j]/10);
				a[j]%=10;
			}
		}
		if(line){/*�Ĥ@�������Ŧ�A����h���Ť@��A��X���G*/
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
