#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	char s;
	long long ans = 0;
	
	while(s=getchar()){
		if(s==-1) break;
		if(s=='1' || s=='0'){/*Ū�J�G�i��Ʀr�A�`�N����s�O�r�� ! ���O�Ʀr !*/
			ans = (ans<<1)+s-'0';/*�����A�ন�Q�i��Ʀr�x�s*/
			if(ans>=131071){
				ans%=131071;
			} 
		}else if(s=='#'){
			if(ans==0){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
				ans=0;
		}
	}
}
	return 0;
}
